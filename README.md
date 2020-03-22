# nihtiu
*(air or wind on the Chorotega extinct language)*

The purpose of this project is to discuss and to provide/invent solutions to deal with the lack of equipment to work with the #Covid-19 #coronavirus.

The idea has been taken from Johns Hopkins Emergency Medicine Resident Julian Botta (Twitter: @julianbotta) published document ["Specifications for simple open source mechanical ventilator"](https://docs.google.com/document/d/1FNPwrQjB1qW1330s5-S_-VB0vDHajMWKieJRjINCNeE/preview?fbclid=IwAR3ugu1SGMsacwKi6ycAKJFOMduInSO4WVM8rgmC4CgMJY6cKaGBNR14mpM), together with other technical and theoretical sources and some spice from the project creator.

There are several alternatives to work the problems:

* To design and to create new systems
* To retrofit obsolete or damaged existing machines
* To addapt existing equipment and/or parts to be used in the needed context

# A Botta System

Botta describes a system whose control could be performed by Arduino or Raspberry Pi machines.

There is the main issue the machine must accomplish, although there seem to be more related problems.

* The lack of other medical material
* Many patients and small quantity of exhausted medical staff
* Physical space for patient accomodation
* A very dangerous contagious environment

As the machines must be carefully tuned for each case, an knowledable person must check what is happening to re-tune the machine.  If the machine is an independent device, that must be done being there with the person.

So, it seems more appropriate to network the machines and to have an isolated remote control center that could monitor what is happening with each machine and that can deliver the required commands to each one.

Oh the other side, it is easier to create hardware and sensor control logic using Arduino level machines that Single Board Computers.  But Arduino logic for a networked environment could be very difficult to obtain.  

A possible solution is to use both, an Arduino and a Raspberry Pi or similar machine connected through a USB cable.

* The Arduino (could be more than one) taking care of the physical logic, controlling the hardware and collecting the data from the sensors.
* The SBC as the logical immediate center, acquiring the data from the Arduino, including more complex reaction logic and with the security and networking behavior.
* A central (with backup) system that permit to monitor each and all machines and that communicate directly with all the Raspberry Pi machines using some private WIFI network.

All the data visualization could be done with HTTP5 logic.  A first version can be done with PHP or similar type of language, while the Arduino logic be encoded with carefully written C++ code (medical level quality).


This setup advantage is that the complexity can be limited to the particular scenario and that, in the case the networed environment fails, the Arduino machine can continue working as such embedded systems can work in isolation from the other computing elements.  This, together with some "emergency" setup for immediate usage.

# Why retrofiting equipment?

This is important when some element in the setup is not easy to create.

Existing machines that are no longer into production could be reassembled and, with some modifications, could provide the basic functions.

Also, they have "complex" parts that can be used to create a Botta System.

# Part addaptation

In this case, the system could use some already created parts, even replacement parts created to specific medical equipment.


In all these cases the challenge is how to obtain a minimum usable working machine, not a full fleated deluxe system (this is a WAR ZONE where many characteristics must be avoided).

# DIY sense

This type of systems can't be designed for complex built scenarios as, in many cases, the sophisticated infrastructure doesn't exist.

This is why an Arduino or a Raspberry Pi are being discussed and not more complex control machines.  However, the software by itself could be complex, just that the software setup must be extremely easy to accomplish, as the people involved with the immediate patient treatment need the machines working quickly and have no time to read manuals.

# Related projects

[Code Live Ventilator Challenge](https://www.agorize.com/en/challenges/code-life-challenge)

[7 open hardware projects working to solve COVID-19](https://opensource.com/article/20/3/open-hardware-covid19)
