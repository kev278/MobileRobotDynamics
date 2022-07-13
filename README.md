# 3-Wheeled Omni-Directional Robot Dynamics

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
A State-Space representation of the Dynamic Model is implemented in C++. The model parameters used are the ones provided in the paper. You can change the parameters in the CSV file to implement your model.
<br><br>

---
## Usage

This repo consists of Header files only. You can implement your model by creating your own main.cpp file. Ths repo is itended to be used as a starting point for implementing your controls. A sample main.cpp file is providedin each foler. You can run the files to check the sample output.
	
---