
var Particle = require('particle-api-js');
var particle = new Particle();
var timerId;
var lastUpdated;
var currentTweet;
var lastTweet;

particle.login({
    username: process.env.particle_username, 
    password: process.env.particle_username });

var Twitter = require('twitter');

var client = new Twitter({
  consumer_key: process.env.twitter_ck,
  consumer_secret: process.env.twitter_cs,
  access_token_key: process.env.twitter_atk,
  access_token_secret: process.env.twitter_ats,
});

/**
 * Stream statuses filtered by keyword
 * number of tweets per second depends on topic popularity
 **/
client.stream('statuses/filter', {track: 'javascript'},  function(stream){
  stream.on('data', function(tweet) {
    console.log(tweet.text);
    currentTweet = tweet.text;
    lastUpdated = Date.now();
    if (!timerId) {
	    timerId = setInterval(particleServiceTimer, 10000);	  
	}
    
  });

  stream.on('error', function(error) {
    console.log(error);
  });
});

function particleServiceTimer() {
	if (lastTweet !== currentTweet) {
        var publishEventPr = particle.publishEvent({ name: 'writeRow1', 
            data: currentTweet, 
            auth: process.env.SPARKACCESSTOKEN });
        
        lastTweet = currentTweet;
        
        publishEventPr.then(
            function(data) {
                if (data) { console.log("Event published succesfully") }
            },
            function(err) {
                console.log("Failed to publish event: " + err)
            }
        );
        console.log('Sending to spark service.');
        if (Date.now() - lastUpdated > 15000) {
            clearInterval(timerId);
            timerId = null;
        }    
    }
    
}
