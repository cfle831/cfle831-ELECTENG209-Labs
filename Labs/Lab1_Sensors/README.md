<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Lab 1 Notes

#### 23/07/26



## 1.1

Estimated:

* Voltage split evenly on each resistor, so 7V for load
* I=V/R, only one current in the circuit that is 0.5A
* P = IV so 3.5W

Measured:

* Load Voltage of 7V
* Load Current of 500mA
* Power delivered to load 3.5W



###### 1.2

estimates (theoretical value) match the simulated value, so Ltspice must be using ideal models for components



###### 1.3

Time step should be 0.1 Milliseconds

Stop time should be 0.4 Seconds

###### 1.4

Time constant of circuit with 4mH inductor: 0.00125 seconds

Time constant of circuit with 25.3µF capacitor: 0.02 seconds

inductor circuit would reach steady state, capacitor circuit would not (current stop time is 0.4 seconds)



###### 1.5

Calculated for the Inductor circuit, ignoring resistor:

* RMS Current: 7A
* RMS Voltage: 14V
* Average Power: 0W (Always 0 in purely reactive circuit)
* Peak Instantaneous Power: 196W

Simulated, with resistor:

* RMS Current: 1.1414A
* RMS Voltage: 14.001V
* Average Power: 0.274W
* Peak Instantaneous Power: 38W





Calculated for the capacitor circuit, ignoring resistor:

* RMS Voltage: 87.75V
* RMS Current: 1.11A
* Average Power: 0W (Always 0 in purely reactive circuit)
* Peak Instantaneous Power: 97.4

Simulated, with resistor

* RMS Voltage: 21.706
* RMS Current: 1.11A
* Average Power: 2.71mW
* Peak Instantanteous Power; 38W





Calculated for resistor circuit:

* RMS Voltage: 14V
* RMS Current: 1.12A
* Average Power: 15.68W
* Peak Instantaneous Power: 31.36W

Simulated:

* RMS Voltage: 14.01V
* RMS Current: 1.21A
* Average Power: 15.68W
* Peak Instantaneous Power: 31.14W





###### 1.6

Accuracy can be improved by decreasing the size of the timestep. this can/would cause simulations to take longer to compute, due to more points being calculated.

I observe smoother lines, and longer simulation time, but no significant changes to the data



###### 1.7

Capacitor circuit:

* RMS voltage increases to 24V
* RMS current stays the same
* Peak instantaneous power increases to 40W
* Average power decreases to 20.3nW

Inductor Circuit:

* RMS current increases to 1.5A
* RMS voltage stays the same
* Peak instantaneous power increases to 40.5W
* Average power decreases to -3.6mW

So the average power moves significantly towards the expected value of 0W. and instantaneous power peak increases.





2.1

Maximum RMS load voltage: 15.4

Minimum RMS load voltage: 12.6



Maximum RMS load current: 0.595

Minimum RMS load current: 0.160



2.2

Theoretical Values

* Load current (IL(rms)): 0.5004A
* Real Power (W): 12.517W
* Reactive Power (VAR): 6.291 VAR
* Apparent Power (VA): 14.009 VA

Simulated Values

* Load current (IL(rms)): 0.550A
* Real Power (W): 6.25W
* Reactive Power (VAR): 3.16 VAR
* Apparent Power (VA): 7 VA

The results show a similar current value, but the power is exactly half what I calculated.

This is due an error i made, where i calculated the power values using non-RMS values for Current and voltage, when i was supposed to be using RMS



2.3

Theoretical Values



* Load current (IL(rms)): 0.1841
* Real Power (W): 2.542
* Reactive Power (VAR): 0.4259
* Apparent Power (VA): 2.577

Simulated Values

* Load current (IL(rms)): 0.18409A
* Real Power (W): 2.5418
* Reactive Power (VAR): 0.426
* Apparent Power (VA): 2.57726

Results match, because the simulation is using a real inductor



3.1

I determined that a 0.1 Ohm resistor would be suitable for this, as it's average power dissipation is 128mW (Simulated).



3.2

shunt resistor of 0.1 Ohm

For Source VA of 7.5, Vrms of 12.6

* RL: 16.943 Ohm:
* IL: 0.59523 A:
* Vis Theoretical: 0.084 V
* Vis Simulated: 0.086 V
* Pis Theoretical: 70mW
* Pis Simulated: 76.63mW

For Source VA of 7.5, Vrms of 15.4

* RL: 28.91 Ohm
* IL: 0.487 A
* Vis Theoretical: 0.0689 V
* Vis Simulated: 0.069 V
* Pis Theoretical: 47.44mW
* Pis Simulated: 48mW

For Source VA of 2.5, Vrms of 15.4

* RL: 93.928 Ohm
* IL: 0.162 A
* Vis Theoretical: 0.023 V
* Vis Simulated: 0.0228 V
* Pis Theoretical: 5.27mW
* Pis Simulated: 5.26mW

Pis remains under 200mW for all of the above situations, which includes the limits that would cause the most and least power across the shunt resistor



3.3



Bigger R Value:

* SNR: Higher
* Dissipation (Pis): Larger
* Size: Unsure
* Cost: Unsure

Lower R Values:

* SNR: Lower
* Dissipation (Pis): Lower
* Size: Unsure
* Cost: Unsure



4.1

Ra/Rb ratio: 10, as to step down from 21.7 (15.4Rms) to \~2 V, Rb needs <10% of the voltage. e.g 12

Ra: 10kOhm

Rb: 1kOhm

these values chosen as they are standard resistor sizes



4.2



For Source VA of 7.5, Vrms of 12.6

* RL: 16.943 Ohm:
* IL: 0.59523 A:
* Vvs Theoretical: 1.62
* Vvs simulated: 1.62
* Pvs theoretical Peak: 28.865mW
* Pvs Simulated: 28.84





For Source VA of 7.5, Vrms of 15.4

* RL: 28.91 Ohm
* IL: 0.487 A
* Vvs Theoretical: 1.98V
* Vvs simulated: 19.8V
* Pvs theoretical Peak: 43.12mW
* Pvs Simulated: 43.1mW







For Source VA of 2.5, Vrms of 15.4

* RL: 93.928 Ohm
* IL: 0.162 A
* Vvs Theoretical: 1.98V
* Vvs simulated: 1.97 V
* Pvs theoretical: 43.12mW
* Pvs Simulated: 43.1mW



The 2V p-p requirement is met, barely, but 4.1 specifically states 'about 2V' so this is satisfactory.

The power dissipation (Peak) is under 100mW in these cases, which is acceptable















