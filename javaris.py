import datetime
import pyttsx3
import speech_recognition as sr
import wikipedia
import webbrowser
import os
import smtplib


def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def wishme():
    hour = int(datetime.datetime.now().hour)
    if 0 <= hour < 12:
        speak("Good morning Nishant!!")
    elif 12 <= hour < 18:
        speak("Good afternoon Nishant!!")
    else:
        speak("Good Evening Nishant!!")

    speak("I am Jarvis. How may I help you?")


def takecommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source, phrase_time_limit=5)
    try:
        print("Recognising...")
        query = r.recognize_google(audio, language="en-in")
        print("User said: ", query)
        return query
    except Exception:
        #        print(e)
        print("Please say it again....")
        return "None"


def sendEmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.login('bansalnishant3516@gmail.com', 'Password')
    server.sendmail('bansalnishant3516@gmail.com', to, content)


engine = pyttsx3.init('sapi5')

# Getting the voices available
voices = engine.getProperty('voices')

# setting the voice
engine.setProperty('voice', voices[1].id)

if __name__ == "__main__":

        wishme()

        query = takecommand().lower()
        if 'wikipedia' in query:
            speak("Searching wikipedia....")
            query = query.replace('wikipedia', '')
            results = wikipedia.summary(query, sentences=2)
            speak('According to wikipedia')
            speak(results)
            print(results)

        elif 'open youtube' in query:
            webbrowser.open("youtube.com")

        elif 'open stackoverflow' in query:
            webbrowser.open("google.com")

        elif 'play music' in query:
            music_dir = None
            songs = os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir, songs[0]))

        elif 'the time' in query:
            strtime = datetime.datetime.now().strftime("%H:%M:%S")
            speak("the time is ", strtime)

        elif 'open code' in query:
            codepath = ""
            os.startfile(codepath)

        elif 'email to harry' in query:
            try:
                speak("What should I say?")
                content = takecommand()
                to = ""
                sendEmail(to, content)
                speak("Email sent successfully!!")
            except Exception as e:
                print(e)
                speak("Sorry!! I was unable to deliver the mail")
