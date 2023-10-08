### Overview of PMIC IC working 

**Boost Charger Power Source:** The main boost charger in the system is powered from the boost output known as VSTOR. It activates when the VSTOR voltage rises above a certain threshold, VSTOR_CHGEN, which is typically 1.8 volts. This threshold is important because it allows the boost charger to start working when, for example, a partially discharged battery is connected to VBAT.

**Harvesting Energy from Low Voltage Sources:** The boost charger is designed to extract power from low voltage output sources like TEGs (Thermoelectric Generators) or single/dual-cell solar panels. It can work with input voltages as low as VIN(DC), which has a minimum of 100 millivolts.

**Cold Start Circuit:** When the system starts with VSTOR and VBAT both below 100 millivolts (e.g., during a cold start), the cold start circuit requires at least VIN(CS), typically 600 millivolts, to charge VSTOR up to 1.8 volts.

**Maximum Power Point Tracking (MPPT):** The bq25570 incorporates a programmable MPPT sampling network to optimize power transfer into the device. We can control the fraction of open circuit voltage that is sampled and held using VOC_SAMP.
VOC_SAMP can be pulled high (80%) or low (50%) or set using external resistors. The sampled voltage is maintained via internal circuitry and an external capacitor (CREF) connected to the VREF_SAMP pin.

**MPPT for Solar Panels:** Solar panels often have a maximum power point (MPP) that corresponds to 80% of their open circuit voltage. By connecting VOC_SAMP to VSTOR, we can set the MPPT threshold to 80%. The IC then regulates the voltage on the solar cell to ensure that the VIN_DC voltage doesn't drop below 80% of the solar panel's open circuit voltage.

---

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
