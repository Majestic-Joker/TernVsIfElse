## Tern VS If/Else
### Joshua Beaty
### Description:

This is a project to determine if the terniary operator saves a significant amount of real time off of a program's runtime.
The reason this test is on github instead of replit is due to the limitations of using small data sets on replit. I'd like to be able to run a test on 1+ billion inputs to see if there's a change in results.

The basic initial version I ran on replit can be found [here](https://replit.com/@JoshuaBeaty/BasicVsFancy#main.cpp)
To convert time results I use [this](http://convert-units.info/time/second/1.0E-7)
To view/edit large data files, I used Liquid Technologies' ["Large File Editor"](https://www.liquid-technologies.com/large-file-editor)

#### Example

- Input: 
    - 4 2
    - 8 5
    - 1 1
    - etc.


- Output V1: 
    - ==Ternary Operation==
    - Total Branches: 1000000
    - True Branches: 445041
    - False Branches: 554959
    - Executed in: 1.36e-03 seconds
    - 
    - ==If/Else Operation==
    - Total Branches: 1000000
    - True Branches: 445041
    - False Branches: 554959
    - Executed in: 1.471e.03 seconds

### Files

|   #   | File                       | Description                                                         |
| :---: | -------------------------- | ------------------------------------------------------------------- |
|   1   | [opTestV1](./opTestV1.cpp) | Version 1 of the solution file, only runs a specified result        |
|   2   | [opTestV2](./opTestV2.cpp) | Version 1 of the solution file, runs for input files 10 - 1 billion |
|   3   | [randomNumbers](./rng.cpp) | File that generates 10 - 1 billion lines of data in separate input files. |

### Instructions

- run rng.exe to generate the 9 input files
- run opTestV2.exe to generate an output file showing the results
- feel free to edit the .cpp files to generate different data sets or run V1 on different data sets.