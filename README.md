# CL_Triangle

command line tool for calculating the area of a triangle based 
on the length of its sides using Heron's formula. Units are arbitrary.

$$ s = {(a + b + c)\over2 } $$

$$ Area = {\sqrt{s(s - a)(s - b)(s - c)}} $$

Where a, b, and c are the lengths of the sides and s is the semiperimeter of the triangle.

## Usage
---

```
Usage: cl_triangle [a] [b] [c]...

where [a] [b] [c] are integers or decimals, in standard or exponential notation

Examples: 
cl_triangle 3 4 5
>>> 6.000000e+00

cl_triangle 3.5 4.5 5.5
>>> 7.854885e+00

cl_triangle 3.54e-15 4.52e-15 5.59e-15
>>> 7.988918e-30

cl_triangle 3.998e+15 4.322e+15 5.481e+15
>>> 8.562048e+30
```

## Building from source
---

This project uses cmake to manage cross platform building.

### UNIX
---

make sure you have the required build tools.

Debian based distros:

```
sudo apt install build-essential snapd
sudo snap install cmake
```

Arch based distros:

```
sudo pacman -S base-devel cmake
```

Then to generate build files and build the project:

```
cd cl_triangle
bash build.sh
```

binary location: 
<br />
`${project_dir}/build/cl_triangle`

### Windows
---
This project makes use of the POSIX regex library which is not available on windows.

Setting up a visual studio project:

building:
