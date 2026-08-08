# Smart Irrigation Controller

> **Archived.** The reviewed and corrected version of this project lives in
> [embedded-iot-projects / smart-irrigation](https://github.com/Penchal9959/embedded-iot-projects/tree/main/smart-irrigation), alongside the others from the same series. Work happens there;
> nothing here changes.

## What this was

A soil-moisture and climate monitor that logs to ThingSpeak over WiFi, so a
growing room can be checked from anywhere. It was built for mushrooms, which
care about humidity more than most crops.

This is the one project in the series that uses a NodeMCU rather than an
Arduino UNO, because it needs WiFi.

## Hardware

NodeMCU (ESP8266), soil moisture probe, DHT11 temperature and humidity sensor,
relay-driven pump.

## Known defects

A WiFi SSID and password and a ThingSpeak write API key were hard-coded here.
All three have been removed from this repository's history. The maintained
copy reads them from a `secrets.h` that is not committed, with a
`secrets.example.h` alongside it. The ThingSpeak channel those keys belonged
to has since been deleted, which invalidates the key.

## Why it was archived

Twelve one-off repositories of two files each is not a portfolio, it is a
list. They were consolidated into one maintained repository with the
documentation and the build check they never had. This one is kept so
existing links still resolve.

## Licence

[MIT](LICENSE)
