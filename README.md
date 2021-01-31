[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/mucahitkurtlar/Watchdog-Telegram-Bot/">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Watchdog Telegram Bot</h3>

  <p align="center">
    NodeMCU based home automation and security system using Telegram API.
    <br />
    <a href="https://core.telegram.org/"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/mucahitkurtlar/Watchdog-Telegram-Bot/issues">Report Bug</a>
    ·
    <a href="https://github.com/mucahitkurtlar/Watchdog-Telegram-Bot/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project


Watchdog can control lights, notify you about motions, power/internet cuts when you are not at home! Watchdog do this all things using Telegram API. 


### Built With

Watchdog built with these libraries and frameworks:
* [ESP8266WiFi](https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html)
* [WiFi](https://www.arduino.cc/en/Reference/WiFi)
* [WiFiClientSecure](https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFiClientSecure)
* [UniversalTelegramBot](https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot)
* [ArduinoJson](https://arduinojson.org/)
* [Telegram API](https://core.telegram.org/)



<!-- GETTING STARTED -->
## Getting Started

You can use this project with following steps.

### Prerequisites

* NodeMCU
* PIR Motion Sensor
* IRFZ44N
* NPN BJ Transistor (I used BC547)
* LED Strip
* 2 x 10K resistor


### Installation

1. Open Telegram app and search for BotFather.
2. Click or type "/start" and follow the inctructions.
3. Note the "bot token".
4. Now search for IDBot and do the same things at step 2.
5. Note the "id"
6. Clone the repo
    ```sh
    git clone https://github.com/mucahitkurtlar/Watchdog-Telegram-Bot.git
    ```
7. Create "secrets.h" file in "telegram-bot" folder.
8. Define following macros and consts
    ```C
    #define BOT_TOKEN "XXXXXXXXXX:XXXXXXXXXXXXXXXXXXXXXXXXXXXXX" //Enter the bot token
    #define CHAT_ID "XXXXXXXXXX" //Enter your chat id

    const char *ssid = "XXXXXXX"; //SSID of WiFi
    const char *pass = "XXXXXXX"; //and WiFi password
    ```
9. Make sure all libraries and boards installed from Arduino IDE borad and library manager.
10. Upload your sketch to the board
11. Send "/start" message to your bot and enjoy :smile:




<!-- LICENSE -->
## License

Distributed under the GPL. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Mücahit KURTLAR - [@mucahit_kurtlar](https://www.instagram.com/mucahit_kurtlar/)

Project Link: [https://github.com/mucahitkurtlar/Watchdog-Telegram-Bot](https://github.com/mucahitkurtlar/Watchdog-Telegram-Bot)




<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/mucahitkurtlar/Watchdog-Telegram-Bot.svg?style=for-the-badge
[contributors-url]: https://github.com/mucahitkurtlar/Watchdog-Telegram-Bot/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/mucahitkurtlar/Watchdog-Telegram-Bot.svg?style=for-the-badge
[forks-url]: https://github.com/mucahitkurtlar/Watchdog-Telegram-Bot/network/members
[stars-shield]: https://img.shields.io/github/stars/mucahitkurtlar/Watchdog-Telegram-Bot.svg?style=for-the-badge
[stars-url]: https://github.com/mucahitkurtlar/Watchdog-Telegram-Bot/stargazers
[issues-shield]: https://img.shields.io/github/issues/mucahitkurtlar/Watchdog-Telegram-Bot.svg?style=for-the-badge
[issues-url]: https://github.com/mucahitkurtlar/Watchdog-Telegram-Bot/issues
[license-shield]: https://img.shields.io/github/license/mucahitkurtlar/Watchdog-Telegram-Bot.svg?style=for-the-badge
[license-url]: https://github.com/mucahitkurtlar/Watchdog-Telegram-Bot/blob/main/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/mucahitkurtlar/
