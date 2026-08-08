# Smart Irrigation Controller

> **This repository is archived.** The reviewed and corrected version
> of this project lives in [embedded-iot-projects / smart-irrigation](https://github.com/Penchal9959/embedded-iot-projects/tree/main/smart-irrigation), alongside the
> others from the same series. Work happens there; nothing here changes.

### Why you want the maintained copy

A WiFi SSID and password and a ThingSpeak write API key were hard-coded here. They have been removed from this repository's history; the maintained copy reads them from a `secrets.h` that is not committed. The ThingSpeak channel those keys belonged to has since been deleted.

---

## Original description

Smart Irrigation System using Thingspeak technology is mainly helpful for the farmer to monitor the crop fields. Thingspeak is a platform, we can log in with our Matlab credentials. this system highly used in Mushroom cultivation because Mushroom cultivation is completely done in a particular Room, so this system will monitor room Humidity, temperature, light, and AirQuality. the whole process is we can monitor from anywhere in the world with help of the Thingspeak platform.

Components:

1.NodeMCU
2.DHT11 Temperature Sensor
3.Rain Water Sensor
4.Dumper
5.DC Motor
6.9 V Battery

Skills Used:

1.Arduino IDE
2.Thingspeak service
3.Matlab Credentials


---

> **Superseded.** This project now lives in
> [embedded-iot-projects](https://github.com/Penchal9959/embedded-iot-projects) alongside eleven
> other builds.

## Credentials

WiFi and ThingSpeak credentials are not stored in this repository. To build:

```bash
cp secrets.example.h secrets.h    # then edit secrets.h with your own values
```

`secrets.h` is gitignored.

> **Security note.** Earlier versions of this repository contained a hardcoded WiFi password and a
> ThingSpeak write API key. Both have been purged from the entire git history and the exposed
> values rotated. They were public between 2022 and 2026, so treat the old values as compromised
> regardless.