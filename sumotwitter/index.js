'use strict';
var Twitter = require('twitter');
const Particle = require('particle-api-js');
const particle = new Particle();
var queue = [];

particle.login({
  username: process.env.particle_username,
  password: process.env.particle_password
});

var client = new Twitter({
  consumer_key: process.env.twitter_ck,
  consumer_secret: process.env.twitter_cs,
  access_token_key: process.env.twitter_atk,
  access_token_secret: process.env.twitter_ats,
});

client.stream('statuses/filter', {track: 'nodejs'},  function(stream){
  stream.on('data', function(tweet) {
    console.log(tweet.text); // tweet.text
    const commandArray = tweet.text.split(' ');
    
    commandArray.forEach(r => {
      if (r === 'left') {
          queue.push('l');
      } else if (r === 'right') {
          queue.push('r');
      } else if (r === 'forward') {
          queue.push('f');
      } else if (r === 'back') {
          queue.push('b');
      } else if (r === 'stop') {
          queue.push('s');
      } 
    });
  });

  stream.on('error', function(error) {
    console.log(error);
  });
});

const myInterval = setInterval(() => {
  if (queue.length > 0) {
    const nextCommand = queue.shift();
    var publishEventPr = particle.publishEvent({ 
      name: 'twitterEvent', 
      data: nextCommand, 
      auth: process.env.particle_auth_token });

    publishEventPr.then(
      function(data) {
        if (data) { 
          console.log("Event published succesfully") 
        }
      },
      function(err) {
        console.log("Failed to publish event: " + err)
      }
    );
  }
  
}, 2000);