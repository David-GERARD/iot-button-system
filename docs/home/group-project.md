# 🛒 Group Project — Smart Supermarket IoT System

## 📋 Project brief

### 🎯 Objective summary

You will be asked to think about an IoT project within a "Smart Supermarket" framework. You will be asked to clarify the goal of your project, the expectation in terms of input data and output, and a clear business case. You will then be asked to design the IoT edge, deciding on the sensors and the connectivity protocols you should consider.

### 🏪 Problem description

Assume you are a project leader in a company working on IoT. With SolarEdge's recent acquisition of Hark Systems, the potential for new Smart Supermarkets being deployed has just become even greater — by combining SolarEdge's expertise in energy management with Hark Systems' connections in retail, many new techniques to realise smart shopping are expected to be developed.

Your team's goal is to develop an idea and an IoT project to realise this "New Smart Supermarket". Your team can focus on existing supermarkets or develop an idea from scratch. It is also your team's choice which aspect of the supermarket you deploy your IoT project on.

Your team will be asked to demonstrate your fully operational end-to-end system, as well as write up a team report.

---

## 🗓️ Project timeline

### 📐 Phase 1: Planification

**Sessions 4 and 5**

#### 📝 Outcomes

- 1 repository for the group with a skeleton of the architecture.
- 1 AWS account for the group, with IAM users for each group member.
- Branches with draft pull requests for each feature (at least 1 per student).
- A planning report (due before Session 6) detailing the business case, system architecture, and implementation plan,  including a table listing each feature, the student responsible for it, and a link to its draft pull request.

#### 🏅 Marking scheme

| Component | Weight |
|-----------|--------|
| Group planning report | 50% |
| Quality of your draft pull request(s) | 50% |

!!! note
    If you have opened multiple draft pull requests, you choose which one you want graded — make that choice visible in your planning report.

### 🛠️ Phase 2: Prototyping

**Sessions 6 and 7**

#### 📝 Outcomes
- Demonstration in Session 8

**✅ Demonstration requirements**

It is expected that the system designed and built by each team will address at least the following baseline technical requirements within the context of the given scenario.

**1. Evidence of the system addressing the project's specifications.**

- Identification of key user requirements and system performance indicators.
- Consideration of deployment challenges and constraints.
- Evidence-informed design choices through literature and empirical evaluation.

**2. Fully operational end-to-end system.**

- The system should comprise at least four different sensor types, one actuator, and one Arduino MKR1010 board.
- Sensor data should be aggregated in an efficient and cohesive manner.
- Sensor data should be transmitted to a cloud platform (for example, IBM Cloud), taking into account any connectivity and storage constraints.

**3. Data capture and storage.**

- Data should be captured and stored in an online database.
- Data should be stored and labelled appropriately to facilitate effective data analysis and processing.
- The system should have mechanisms for downloading data in time-series, table-like format.

**4. User interface.**

- Fully operational and user-friendly dashboard for visualising data from any location.
- The interface should initiate events and actions either due to sensors being triggered or due to manual user input — for example, considering the context of the project scenario, the system should alert the relevant professional about any unusual events.
- Interface should allow remote control of the edge system (see next point) from any location.

**5. Edge control.**

- Edge system parameters should be dynamically configurable from any location.
- Actuators should respond accurately and in real-time, both in open-loop (manual) and closed-loop (automatic) control based on sensor values.

**Additional technical requirements (high-performing teams)**

High-performing teams should also consider the following additional technical requirements.

**1. Resource evaluation.**

- Estimating the edge system's power consumption and taking action to reduce it without sacrificing the minimum expected performance.
- Monitoring and keeping track of the data exchanged between the edge and the cloud, and taking action to optimise bandwidth resources.

**2. Optimised edge system.**

- The system should act as a coordinated wireless network of sensors and actuators.
- The edge modules should allow for portability and the use of a battery-powered source.

**3. Enriched data processing system.**

- Data should include both data from physical sensors and data from relevant external sources, merged efficiently into a single dataset.
- The data storage and processing system should provide failsafe mechanisms for detecting and preventing malfunction.
- The system should provide mechanisms for linking the stored data to an analytics (online or offline) platform.

**4. Security.**

The system should provide as many levels of security as possible, such as:

- For the connectivity between the edge system and the cloud.
- For the data stored, as well as the applications and services running in the cloud.
- On the edge system devices themselves.

#### 🏅 Marking scheme

| Band | Range | Criteria |
|------|-------|----------|
| Exceptional | 90%–100% | The system implemented is unique, showing exceptional levels of originality and creativity, significantly beyond the knowledge and material covered during lectures and workshops. The demonstration is comprehensive, coherent and flawless, addressing above and beyond all the requirements of the project scenario. Arguments, choices and approaches are justified succinctly; outcomes are evaluated rigorously. |
| Outstanding | 80%–89% | The system implemented shows very high levels of originality and creativity, well beyond the knowledge and material covered during lectures and workshops. The demonstration is comprehensive and coherent, addressing all possible requirements specified for the project scenario. Arguments, choices and approaches are justified clearly; outcomes are discussed coherently. |
| Excellent | 70%–79% | The system implemented shows originality and innovation beyond the knowledge and material covered during lectures and workshops. The demonstration is complete and coherent, addressing the requirements specified for the project scenario. Arguments, choices and approaches are justified clearly; outcomes are discussed in a clear and informative manner. |
| Good | 60%–69% | The system implemented shows initiative in bringing together all the knowledge and material covered during lectures and workshops. The demonstration is logical and easy to follow, addressing the requirements within the context of the given project scenario. Arguments, choices, approaches and outcomes are discussed clearly. |
| Reasonable | 50%–59% | The system implemented brings together all the knowledge and material covered during lectures and workshops. The demonstration can be followed and addresses at least all the baseline requirements within the project's context. Arguments, choices, approaches and outcomes are discussed reasonably well. |
| Fail | 40%–49% | The system implemented brings together most but not all of the knowledge and material covered during lectures and workshops. The demonstration can be followed most of the time and addresses the baseline requirements, but may be missing some contextual project scenario points. Arguments, choices, approaches and outcomes are discussed, maybe with some lack of clarity. |
| Clear Fail | 30%–39% | The system implemented fails to properly bring together the knowledge and material covered during lectures and workshops. The demonstration is difficult to follow and/or the system does not meet the baseline requirements defined for the given project scenario. Arguments, choices, approaches and outcomes lack clarity or context. |
| Well below unsatisfactory | 0%–29% | The system implemented has little relevance to the project scenario. The demonstration is confusing. Arguments, choices, approaches and outcomes are inaccurate or irrelevant. |


### 📝 Phase 3: Report

_TBD_

--- 