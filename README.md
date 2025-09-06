# C++ Course Project - Flight Management System

This project implements a flight management system with the following classes:
- `CAddress` - Address management
- `CCrewMember` - Crew member management with employee numbers
- `CPlane` - Aircraft management with serial numbers
- `CFlightInfo` - Flight information management
- `CFlight` - Flight management with crew assignment
- `CFlightCompany` - Company management with crew, aircraft, and flight arrays

## Building the Project

### Option 1: Visual Studio (Recommended)
1. Open `cpp_course_project.sln` in Visual Studio
2. Select Debug or Release configuration
3. Select x64 platform
4. Build the solution (Ctrl+Shift+B)
5. Run the project (F5)

### Option 2: Command Line Build
1. Open Developer Command Prompt for VS
2. Navigate to project directory
3. Run: `msbuild cpp_course_project.sln /p:Configuration=Debug /p:Platform=x64`

### Option 3: Batch File
1. Double-click `build.bat` in the project root
2. Follow the prompts

### Option 4: CMake (Alternative)
1. Install CMake
2. Create build directory: `mkdir build && cd build`
3. Generate project files: `cmake ..`
4. Build: `cmake --build .`

## Project Structure
```
cpp_course_project/
├── main.cpp                 # Main program
├── Address.h/.cpp          # CAddress class
├── CrewMember.h/.cpp       # CCrewMember class
├── Plane.h/.cpp            # CPlane class
├── FlightInfo.h/.cpp       # CFlightInfo class
├── Flight.h/.cpp           # CFlight class
├── FlightCompany.h/.cpp    # CFlightCompany class
├── Constants.h             # Project constants
└── cpp_course_project.vcxproj  # Visual Studio project file
```

## Features Implemented
- Object-oriented design with proper encapsulation
- Operator overloading (+, +=, <<, ==, !=, ++, cast operators)
- Copy constructors, assignment operators, and destructors
- Static member management for serial numbers and employee IDs
- Array management with capacity limits
- Input/output operators for all classes
- Comprehensive error handling and validation

## Requirements Met
✅ All classes implement required constructors, destructors, and operators
✅ Default constructors are deleted as required
✅ Copy constructors and assignment operators implemented
✅ Operator overloading for all specified operators
✅ Static member management for IDs and serial numbers
✅ Array management with proper capacity checking
✅ Helper functions for finding objects by ID/number
✅ Comprehensive testing in main.cpp
