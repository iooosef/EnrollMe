# EnrollMe
---
## Description
In partial fulfillment of academic requirements in ITE 001

## Getting Started
### Requirements
* Windows 10 Operating System (or newer)
* [Microsoft Visual Studio 2019 (or later versions)](https://visualstudio.microsoft.com/vs/older-downloads/)
* [Git](https://git-scm.com/downloads)
* [Vcpkg](https://github.com/microsoft/vcpkg)
* [CrowCpp](https://github.com/CrowCpp/Crow)

## Installation

<details>
  <summary>
    <h3>Visual Studio Installation</h3>
  </summary>

add instructions for instalaltion of VStudio with C++ tools
 
</details>

<details>
  <summary>
    <h3>Git Installation</h3>
  </summary>

add instructions for instalaltion of Git
 
</details>

<details>
  <summary>
    <h3>Vcpkg Installation</h3>
  </summary>

Vcpkg can be installed anywhere; it is recommended to install in `C:\src\`.
(*Create* `C:\src\` *directory if it doesn't exist*).

Clone vcpkg repository.
```pwsh
cd C:\src\
git clone https://github.com/microsoft/vcpkg

```

Bootstrap vcpkg repository.
```pwsh
.\vcpkg\bootstrap-vcpkg.bat
```

In order to use vcpkg with Visual Studio, run the following command (may require administrator elevation):
```pwsh
.\vcpkg\vcpkg integrate install
```

</details>

### Add the ff. Environment Variables
```pwsh
$env:VCPKG_ROOT = 'C:\src\vcpkg'
$env:VCPKG_DEFAULT_TRIPLET = 'x64-windows'
```


