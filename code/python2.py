# -*- coding: utf-8 -*-
#!/usr/bin/python

from TwitterAPI import TwitterAPI
from serial import Serial

import sys
import time
import random

arduinoPort = '/dev/tty.wchusbserial1410'
arduinoBaud = '9600'

ser = Serial(arduinoPort, arduinoBaud, timeout=3)

from auth_twitterfurby import (
    consumer_key,
    consumer_secret,
    access_key,
    access_secret
)

stringToTrack = "#twitterfurby"

api = TwitterAPI(consumer_key, 
                 consumer_secret,
                 access_key,
                 access_secret)


ADJECTIVE = ("fine", "happy", "good", "cool", "nice", "alive")
COLOUR = ("red","blue","green","yellow","aqua","pink","purple","rainbow")
EMOJI = ("")

while True:
    r = api.request('statuses/filter', {'track':stringToTrack})
    print('TwitterFurby ready!')
    for item in r:
        tweet = item['text']
        user = item['user']['screen_name']
        print(tweet, " ", user)
        if "#red" in tweet.split():
            tweet_status = ("@" + str(user) + " set TwitterFurby to RED and Furby are " + random.choice(ADJECTIVE) + " *** Maybe you want to set Furbycolor to " + random.choice(COLOUR) + " ?")
            r = api.request('statuses/update', {'status': tweet_status})
            print(tweet_status)
            ser.write(str.encode("red"))
        if "#green" in tweet.split():
            tweet_status = ("@" + str(user) + " set TwitterFurby to GREEN and Furby are " + random.choice(ADJECTIVE) + " *** Maybe you want to set Furbycolor to " + random.choice(COLOUR) + " ?")
            r = api.request('statuses/update', {'status': tweet_status})
            print(tweet_status)
            ser.write(str.encode("green"))
        if "#blue" in tweet.split():
            tweet_status = ("@" + str(user) + " set TwitterFurby to BLUE and Furby are " + random.choice(ADJECTIVE) + " *** Maybe you want to set Furbycolor to " + random.choice(COLOUR) + " ?")
            r = api.request('statuses/update', {'status': tweet_status})
            print(tweet_status)
            ser.write(str.encode("blue"))
        if "#pink" in tweet.split():
            tweet_status = ("@" + str(user) + " set TwitterFurby to PINK and Furby are " + random.choice(ADJECTIVE) + " *** Maybe you want to set Furbycolor to " + random.choice(COLOUR) + " ?")
            r = api.request('statuses/update', {'status': tweet_status})
            print(tweet_status)
            ser.write(str.encode("pink"))
        if "#yellow" in tweet.split():
            tweet_status = ("@" + str(user) + " set TwitterFurby to YELLOW and Furby are " + random.choice(ADJECTIVE) + " *** Maybe you want to set Furbycolor to " + random.choice(COLOUR) + " ?")
            r = api.request('statuses/update', {'status': tweet_status})
            print(tweet_status)
            ser.write(str.encode("yellow"))
        if "#purple" in tweet.split():
            tweet_status = ("@" + str(user) + " set TwitterFurby to PURPLE and Furby are " + random.choice(ADJECTIVE) + " *** Maybe you want to set Furbycolor to " + random.choice(COLOUR) + " ?")
            r = api.request('statuses/update', {'status': tweet_status})
            print(tweet_status)
            ser.write(str.encode("purple"))
        if "#off" in tweet.split():
            tweet_status = ("@" + str(user) + " turn OFF TwitterFurby and Furby are " + random.choice(ADJECTIVE) + " *** Maybe you want to set Furbycolor to " + random.choice(COLOUR) + " ?")
            r = api.request('statuses/update', {'status': tweet_status})
            print(tweet_status)
            ser.write(str.encode("off"))
        if "#aqua" in tweet.split():
            tweet_status = ("@" + str(user) + " set TwitterFurby to AQUA and Furby are " + random.choice(ADJECTIVE) + " *** Maybe you want to set Furbycolor to " + random.choice(COLOUR) + " ?")
            r = api.request('statuses/update', {'status': tweet_status})
            print(tweet_status)
            ser.write(str.encode("aqua"))
        if "#happy" in tweet.split():
            tweet_status = ("@" + str(user) + " made TwitterFurby realy HAPPY and Furby are " + random.choice(ADJECTIVE) + " *** Maybe you want to set Furbycolor to " + random.choice(COLOUR) + " ?")
            r = api.request('statuses/update', {'status': tweet_status})
            print(tweet_status)
            ser.write(str.encode("furby_happy"))
        if "#alive" in tweet.split():
            tweet_status = ("@" + str(user) + " made TwitterFurby realy ALIVE and Furby are " + random.choice(ADJECTIVE) + " *** Maybe you want to set Furbycolor to " + random.choice(COLOUR) + " ?")
            r = api.request('statuses/update', {'status': tweet_status})
            print(tweet_status)
            ser.write(str.encode("furby_face"))
        if "#rainbow" in tweet.split():
            tweet_status = ("@" + str(user) + " made TwitterFurby in RAINBOW and Furby are " + random.choice(ADJECTIVE) + " *** Maybe you want to set Furbycolor to " + random.choice(COLOUR) + " ?")
            r = api.request('statuses/update', {'status': tweet_status})
            print(tweet_status)
            ser.write(str.encode("rainbow1"))
        if "#heart" in tweet.split():
            tweet_status = ("@" + str(user) + " made TwitterFurby in LOVE and Furby are " + random.choice(ADJECTIVE) + " *** Maybe you want to set Furbycolor to " + random.choice(COLOUR) + " ?")
            r = api.request('statuses/update', {'status': tweet_status})
            print(tweet_status)
            ser.write(str.encode("furby_beat"))
        print("....")
