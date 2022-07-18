# 3-Wheeled Omni-Directional Robot Dynamics

## Please use the **mixed-folders branch** to run the code

## Overview
In this project, I have implemented a working Kinematic Model and Dynamic Model. All model parameters are extracted from a CSV and can be changed based on your model. The input to the model is a fifth order (quintic) position trajectory that is generated from a MATLAB script. The Models can be found in this [paper](https://www.researchgate.net/publication/256089847_Dynamical_Models_for_Omni-directional_Robots_with_3_and_4_Wheels). The dynamic model is represented as a State-Space Model and can be used for implementung control strategies. Multiple control strategies are implemented in [here](https://github.com/kev278/control-strategies). You will simply have to change the State-Space Model to implement the control strategies.

---
## Tools and Frameworks
**C++**

**MATLAB**

**IDE:** VS Code <br>
*(Any IDE of your choice can be used)*

**3rd party libraries:**
- Eigen 3.4.0

---
## Contributions
 
- **Kinematic Model**: <br>
The [paper](https://www.researchgate.net/publication/256089847_Dynamical_Models_for_Omni-directional_Robots_with_3_and_4_Wheels) derives a Kinematic Model that transforms the position trajectory from World Frame to Robot Frame and then maps it to wheel velocities. A C++ implementation of the derived model is provided. 
<br><br>

- **Dynamic Model**: <br>
A State-Space representation of the Dynamic Model is implemented in C++.
<br><br>

---
## Usage

**Step 1:** The parameters.csv file contains all the model parameters. You can change these as per your model.
**Step 2:** The velocityTraj.csv contains velocity trajectories in the world frame. You can add any trajectory that you need to follow.
**Step 3:** Run the main.cpp file
**Step 4:** You can check the output robot acceleration trajectories in the output.csv files. We get these trajectories fro the state space model.
	
---
