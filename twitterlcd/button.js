'use strict';
const Particle = require('particle-api-js');
const particle = new Particle();
const token = process.env.SPARKACCESSTOKEN;
const buttonDevice = process.env.button_device;

particle.login({
    username: process.env.particle_username, 
    password: process.env.particle_password 
});

particle.getEventStream({ deviceId: buttonDevice, auth: token }).then(function(stream) {
   stream.on('event', function(data) {
     console.log(data);
   });
});

// rainbow

var publishEventPr = particle.publishEvent({ name: 'rainbow', data: {}, auth: token });

publishEventPr.then(
  function(data) {
    if (data.body.ok) { console.log("Event published succesfully") }
  },
  function(err) {
    console.log("Failed to publish event: " + err)
  }
);
