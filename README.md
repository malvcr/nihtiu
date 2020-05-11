|![Nihtiu Banner](/docs/images/Nihtiu_Banner.jpg)|
|--------:|
|*(air or wind in the extinct Chorotega language)*|

# Nihtiu Environment

*-- check the Wiki part ... it has important discussions --*

> This project evolves quickly, the same as the knowledge about the Covid-19 disease that motivated it. 
------
> Marco Alvarado  

## The situation

\#Covid19 is a disease caused by a \#coronavirus that appeared as an unexpected war, a situation that surprised everyone in late 2019. In a few months it has been able to decimate even the health systems of strong countries and is causing millions of sick people and thousands of deaths (with a really painful death).  A situation that it is not improving as we like.

At the time of this writing, we have to wait at least months (even around two years) to have a useful vaccine for the disease. Meanwhile, the only successful solution has been the so-called "social distancing", coupled with extreme measures of care and security when being in contact with others or leaving home in some type of forced quarantine at a country level. However, this is a very difficult situation to maintain that is destroying the world economy and will forever change the way our society works.

Key aspects of what needs to be done to resolve the problem lay around medical breathing technology which involves:

### Patients:

1. Covid-19 is a very contagious disease. [r3].

2. In severe cases, the patients need to be connected for weeks to special machines called "ventilators", which help them breathe. Many have died as there were not enough ventilators available when they reached that critical moment, and the hospital Intensive Care Units (ICU) have not enough of them because in normal conditions it is not necessary to use the resources purchasing so many expensive machines.  

3. Not only the ventilation devices are needed; in some countries, the quantity of doctors required to attend patients (and ultimately control the ventilators), is limited.  A reason for this to happen is that many of them are sick from the same disease they try to cure every day [r4], or simply they are exhaust or even near collapse because the overwhelming work needed to take care of the patients [r5].

4. There is a fierce battle in the open market for ventilators, and several countries that make them are forbidding to export any technology that could be used for Covid19 treatment, as it is needed locally.

5. The "standard" ventilator and related machines, although being the only options available to save some people, are far from being the perfect tools to offer treatment for Covid-19.  There are several shortcomings on the existing technology that must be addressed to offer better results.

6. Some patients (the quantity is unknown right now because was not a priority to count them in the moment), have temporary or permanent damage in their lungs “after” being cataloged as cured.  There are cases where between 20 to 30% of their lung capacity have been lost [r2].


### The Economy
       
1. When people are sick they cannot work and in order for healthy people to stay away from the disease, many have been confined far from their workplace. 

2. It is simply very dangerous to continue doing everything as usual and as the ventilators are scarse, the authorities chose to sacrifice the economy instead of the population.

3. For some recovered people, it is complicated to return to a "normal life", hurting the already weak working environment.


This means considering a different type of breathing technology that is more comprehensive than currently available, where a single doctor has the possibility of offering treatment to more people and even, from a safer place than constantly visiting them. Furthermore, being a new and relatively unknown disease, every piece of information about how patients pass through the disease is important in helping others heal. It might even be necessary to collect detailed information from various countries in real time to understand what is happening with the disease and each type of treatment.

## The Project: Nihtiu

The project’s purpose is to describe distributed breathing technology for world-level war-like scenarios as the one the Covid-19 pandemic have defined.

Why distributed and why this is not just a ventilator?

* As previously described, ventilators are no perfect and the needs go beyond what an independent ventilator can do.

* Not every country has the same resources.  The definition must be generic and flexible and the investment must be effective and intelligent.

* It is important to separate what must be discarted than what can be reused many times, to improve the investment to the maximum.  So, what be done must be a "components based" product.

* Things must be practical, clear and clean to use always, and easy to fix.

* Today a solution could be good but as more information is acquired about the disease, could require improvements or complete rewritings.  Each element must be able to be used in different situations.

* Easy to use for the most of the people in the right scenarios.

* The final product must be working as a huge bee hive.  Every part can work independently but as a whole they must show incredible power.

* Licensing must be flexible.  Right now all these things are created under the MIT licensing umbrella, but if there are better options, they will applied when needed.

### The Environment

The Nihtiu environment is assembled with the most basic functional element: the **Breathing Unit**, that helps to compose a full set of functionality when aggregated with special docking **stations**.

![Nihtiu Environment](/docs/images/Nihtiu-Modular.png)

 **Breathing Unit** 

The Breathing Unit is a self contained tiny breathing device.

It is a "small enough" machine containing all the required components to help a person to breathe, following a customized ventilation mode (designed exclusively for that person).

Has enough power to work independently for some minutes.

 **The stations**

![Nihtiu Scenarios](/docs/images/Nihtiu-Scenarios.png)

They are a "docking" platform where a Breathing Unit is docked, providing "extra" functions to it.  There are different types of stations depending on the usage:

* *Portability Station*: A type of case offering extra power and communications for the patient to carry the Breathing Unit, making it a real portable device.

* *Home Base Station*: Provides convenient capacities for using the Breathing Unit at home for extended periods of time.

* *Hospital Base Station*: Used when the patient lays in the Intensive Care Unit at a hospital or similar institution.

* *Hospital Control Station*: The one permits to re-code the Breathing Unit to perform the customized operation modes, according with a doctor's specification.

 **Node Controller**

This is an *aggregation* device having enough functionality to offer the central perspective of the distributed environment.  It could also cooperate with othher Node Controllers, to have a higher grade image about what is happening with the individual patients and how they related one with the other.

These Nodes can also cooperate with Data processors, offering extra funcionality as transactional based service providers, and communicate with those machines in the wild through Telemetry concentrators.

Taking all this into consideration, the Nihtiu Environment is defined:

![Nihtiu Environment](/docs/images/Nihtiu-Environment.png)

Here, there are ventilators, but they are networked and have centralized monitoring and control systems.  The different *stations* provide all the required use cases, for the patients to stay at the hospital when required or to be able to go home "with" a breathing assistant to continue having a life.

Notice that the Home environment could also be defined in a contaminated zone.  This is following the successful method used in Costa Rica, where the patients stay in their homes and medical staff visit them regularly, reducing the need to compromise hospitals and clinics.  Only severe cases are worked within the ICUs.


The environment also can be enriched with extra medical equipment and data processing, to have a better understanding about what is really happening with the patient and the surrounding population.  This includes a complete information system (with the corresponding data model), and communication protocols correctly defined with high grade security.


## The initial system

The initial work is to understand the problem and to define an initial ventilator system.

This system is a multi-computing device created with Arduinos and Single Board Computers, together with a set of sensors and actuators (motors, screens, sound devices, etc.).  The databases are sqlite embedded instances but with full relationship definitions between all the contained elements.

As these are the basic elements, they are coded with enough care and clear enough terms for an information science professional to decode what is happening inside.  And the inner system behavior is like a transactional system instead of obscure and difficult to follow interleaved functionality.

## Additional (project related) publications

[[x1]- Ventilators in Covid-19 times](https://medium.com/@malvcr/ventilators-in-covid-19-times-f570ae2bcc64?source=friends_link&sk=d4f600e13792742de84ac8dbd94e4145)

## Same theme projects

[[p1]- Botta: Specifications for a simple open source mechanical ventilator](https://docs.google.com/document/d/1FNPwrQjB1qW1330s5-S_-VB0vDHajMWKieJRjINCNeE/edit)

[[p2]- Rapidly manufactured ventilator system specification](https://www.gov.uk/government/publications/coronavirus-covid-19-ventilator-supply-specification/rapidly-manufactured-ventilator-system-specification)

[[p3]- Code Live Ventilator Challenge](https://www.agorize.com/en/challenges/code-life-challenge)

[[p4]- 7 open hardware projects working to solve COVID-19](https://opensource.com/article/20/3/open-hardware-covid19)

[[p5]- IFIXIT: Help us crowdsource repair information for medical equipment](https://www.ifixit.com/News/36354/help-us-crowdsource-repair-information-for-Hospital-Equipment)

[[p6]- OXYGEN](https://www.oxygen.protofy.xyz/)

[[p7]- UCR:Respiradores de emergencia para pacientes de Covid 19 podrían ser de fácil construcción](https://www.ucr.ac.cr/noticias/2020/03/25/respiradores-de-emergencia-para-pacientes-de-covid-19-podrian-ser-de-facil-construccion.html)

[[p8]- TEC trabaja en la creación de respiradores artificiales](https://delfino.cr/2020/03/tec-trabaja-en-la-creacion-de-respiradores-artificiales)

[[p9]- Open Source Ventilator](https://opensourceventilator.ie/)

[[p10]- How innovation is helping ease a dangerous ventilator shortage](https://www.weforum.org/agenda/2020/03/coronavirus-ventilators-covid19-healthcare/)

[[p11]- Nvidia’s top scientist develops open-source ventilator that can be built with $400 in readily available parts](https://techcrunch.com/2020/05/01/nvidias-top-scientist-develops-open-source-ventilator-that-can-be-built-with-400-in-readily-available-parts/)

[[p12]- NASA-Developed Ventilator Authorized by FDA for Emergency Use](https://www.nasa.gov/press-release/nasa-developed-ventilator-authorized-by-fda-for-emergency-use)

## References

[[r1]- Brigham and Women's Hospital COVID-19 Clinical Guidelines](https://covidprotocols.org/)

[[r2]- Coronavirus: some recovered patients may have reduced lung function and are left gasping for air while walking briskly, Hong Kong doctors find](https://www.scmp.com/news/hong-kong/health-environment/article/3074988/coronavirus-some-recovered-patients-may-have)

[[r3]- How The Novel Coronavirus And The Flu Are Alike ... And Different](https://www.npr.org/sections/goatsandsoda/2020/03/20/815408287/how-the-novel-coronavirus-and-the-flu-are-alike-and-differen)

[[r4]- Coronavirus: One in four NHS doctors 'sick or in isolation'](https://news.sky.com/story/coronavirus-one-in-four-nhs-doctors-sick-or-in-isolation-11965886)

[[r5]- Doctors: COVID-19 pushing Italian ICUs toward collapse](https://www.cidrap.umn.edu/news-perspective/2020/03/doctors-covid-19-pushing-italian-icus-toward-collapse)

[[r6]- Ventilators Aren’t Going to Cure COVID-19. Here’s What They Can Do.](https://www.propublica.org/article/ventilators-arent-going-to-cure-covid-19-heres-what-they-can-do)

[[r7]- Respiratory Support in Novel Coronavirus Disease (COVID-19) Patients, with a Focus on Resource-Limited Settings](https://www.ajtmh.org/content/journals/10.4269/ajtmh.20-0283)

[[r8]- Why Some Doctors Are Now Moving Away From Ventilator Treatments for Coronavirus Patients](https://time.com/5818547/ventilators-coronavirus/)

[[r9]- Reducing Care Fragmentation](http://www.improvingchroniccare.org/downloads/reducing_care_fragmentation.pdf)

[[r10]- Networked medical device cybersecurity and patient safety:  Perspectives of health care information cybersecurity executives](https://www2.deloitte.com/content/dam/Deloitte/us/Documents/life-sciences-health-care/us-lhsc-networked-medical-device.pdf)

[[r11]- IoT Platform for Healthcare System: Protocols Interoperability](https://www.ripublication.com/ijaer17/ijaerv12n22_106.pdf)

[[r12]- IoT Protocols for Health Care Systems: A Comparative Study](https://www.researchgate.net/publication/328967304_IoT_Protocols_for_Health_Care_Systems_A_Comparative_Study)

[[r13]- The Difference Between CPAP, BiPAP, and Ventilators](https://aeroflowinc.com/need-ventilator-instead-bipap-cpap/)

[[r14]- Material Linear-Actuator for Robotics](https://hackaday.io/project/157004-material-linear-actuator-for-robotics)
