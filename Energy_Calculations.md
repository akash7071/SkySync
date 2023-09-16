### **SoC**

EM2-Wakeup->Measure Data->Transfer Data->EM2

Assuming a 10 minute cycle, 30s in EM0 mode and 570s in EM2 mode with Radio on


EM2 - Full RAM retention and RTC running from LFRCO in precision
mode

| State         | Current (mA) | Power (mW) | Weight | 
|-------------------|--------|------|-------------|
| EM2  | 0.7 | 2.31 | 0.95 | 
| EM0  | 6 | 19.8 | 0.05 | 

The average currents for EM2 and EM0 have been referred from IoT project numbers. For a bar chart we can just assume different stages like it flip flopping between EM2 and EM0

Weighted Average of Current = **0.965mA**, at 3.3V
Weighted Average Power = **3.1845mW**

---
### BME280
In weather monitoring mode.

| State         | Current (mA) | Power |Weight |
|-------------------|-------|-------| ------------|
| Deep Sleep  |   0.0001 | 0.33 uW | 0.98  |
| Active           | 0.7  |  2.31mW  |  0.02  |

Needs about 8ms to wakeup and measure data.

Considering one data measurement every 10 minutes. 

Weighted Average Current = **0.01437mA**, at 3.3V
Weighted Average Power = **0.0474mW**

---
### ENS160
| State         | Current (mA) | Power |Weight |
|-------------------|-------|-------| ------------|
| Deep Sleep  |   0.01  | 18 uW | 0.7  |
| Active           | 29  | 52.2 mW | 0.3  |

The sensor needs 3 minutes to warm up, considering one measurement every 10minutes

Weighted Average Current = **8.7mA**, at 1.8V
Weighted Average Power = **15.66mW**

---
### AS7331

| State         | Current (mA) | Power | Weight |
|-------------------|-------|-------| ------------|
| Deep Sleep  |   0.001  | 3.3 uW |0.98  |
| Active           | 2  | 6.6 mW | 0.02  |

Needs about 70ms to wakeup and measure data.

Considering one data measurement every 10 minutes. 

Weighted Average Current = **0.0401mA**, at 3.3V
Weighted Average Power = **0.13233mW**

