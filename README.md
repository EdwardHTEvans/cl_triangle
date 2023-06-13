# CL_Triangle

This project contains a basic command line tool for calculating the area of a triangle based on the length of its sides using Heron's formula.

$$ s = {(a + b + c)\over2 } $$
$$ Area = {\sqrt{s(s - a)(s - b)(s - c)}} $$

Where a, b, and c are the lengths of the sides and s is the semiperimeter of the triangle.

## Usage

```
Usage: cl_triangle [a] [b] [c]...

command line tool for calculating the area of a triangle based on the length of its sides using Heron's formula.

Options:
  -h, --help             show help

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

Setting up a visual studio project:

building:
