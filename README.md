# EnrollMe

---
## Description
In partial fulfillment of academic requirements in ITE 001


## Dependencies
* Windows 10 Operating System (or newer)
* [Microsoft Visual Studio 2019 (or later versions)](https://visualstudio.microsoft.com/vs/older-downloads/)
* [Git](https://git-scm.com/downloads)
* [Vcpkg](https://github.com/microsoft/vcpkg)
* [CrowCpp](https://github.com/CrowCpp/Crow)
* [SQLite](https://www.sqlite.org/cintro.html)
* [htmx](https://github.com/bigskysoftware/htmx)
* [Bootstrap](https://getbootstrap.com/)

## Setup

### Dependencies Installation

### Visual Studio
Install **Visual Studio 2019 *(or later versions)***
Include the ff. Workloads:
* Desktop Development with C++

### Git
*[Click for instructions in installing Git](https://phoenixnap.com/kb/how-to-install-git-windows)*

<details>
  <summary>
    <h3>Vcpkg Installation</h3>
  </summary>

Vcpkg can be installed anywhere; it is recommended to install in `C:\src\`.
(*Create `C:\src\` directory if it doesn't exist*).

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

### Project Development Setup

1. Enter the ff. code in **Windows Powershell** to set the environment variables:
```pwsh
$env:VCPKG_ROOT = 'C:\src\vcpkg'
$env:VCPKG_DEFAULT_TRIPLET = 'x64-windows'
```

2. Also enter the ff. code to clone the repository:
```pwsh
git clone https://github.com/iooosef/EnrollMe.git
```

3. Open Visual Studio

4. Click `Continue without code →`

5. In the Menu Bar, click `File`  → `Open` → `Cmake...`

6. Navigate to `.\EnrollMe\` directory, then open `CMakeLists.txt`

7. In the **Developer PowerShell** enter the code to install vcpkg dependencies:
```pwsh
vcpkg install
```

8. Also enter the code to generate the build files:
```pwsh
cmake -B build -S .\ --preset x64-debug
```

9. In Visual Studio click `Debug` menu bar, then `Debug and Launch Settings for EnrollMe`.

10. inside `launch.vs.json`, add the following below `"name"` to run the web server.
```json
"name": "EnrollMe.exe",
"args": [
  "run"
]
---

11. Debug and Run

<span style="font-size: 10px;" >
<i> Documentation by Group 8 ITE001 - CS11S2 </i> 
<br />
<i> Parayaoan, Joseph Clarence • Clemente, Ken Shelly Charles • Fernandez, Sandrhen • Palaganas, John Michael Dublin</i>
</span>