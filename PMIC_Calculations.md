### Inductor Selection

**Boost Charger Inductor Selection**

The internal control circuitry of the boost charger is engineered to regulate the switching operations, featuring a nominal inductance of **22 µH** with a tolerance of approximately ± 20%.

**Buck Converter Inductor Selection**

The buck converter internal control circuitry is designed to control the switching behavior with a nominal inductance of **10 µH** ± 20%

---

### Capacitors  Selection

**VREF_SAMP Capacitance**

The MPPT operation relies on sampled open circuit voltage, and the input regulation is controlled by the voltage stored on the CREF capacitor, which, due to its sensitivity to leakage, should be of the X7R or COG type to maintain proper operation and maximize power extraction from the input source. We have selected **10 nF** 

**VIN_DC Capacitance**

When dealing with energy harvesters dominated by capacitive source impedance, it is advisable to scale the harvester capacitor according to the output capacitance of the energy source, with a minimum recommended value of **4.7 µF**.

**VSTOR Capacitance**

As per the datasheet, to ensure effective bypassing of high-frequency noise, a 0.01 µF capacitor should be positioned very close between VSTOR and VSS, and it's recommended to include a low equivalent series resistance (ESR) capacitor of at least 4.7 µF in parallel.

**VOUT Capacitance**

The selection of the output capacitor is influenced by transient response behavior and ripple magnitude, with a larger capacitor value, preferably at least 22 µF, between VOUT (pin 14) and VSS (pin 15) to minimize ripple and transient droop.

**Capacitance on VSTOR or VBAT**

---

### Resitors  Selection

Verified the calculations using tool : https://www.ti.com/tool/download/SLUC484
