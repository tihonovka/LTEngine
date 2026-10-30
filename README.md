<div align="center">

# LTEngine

**A small C++20 game engine experiment, built one system at a time.**

![C++20](https://img.shields.io/badge/C%2B%2B-20-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/platform-Windows-0078D4?style=flat-square&logo=windows&logoColor=white)
![API](https://img.shields.io/badge/API-Win32-555555?style=flat-square)
![Status](https://img.shields.io/badge/status-experimental-orange?style=flat-square)

*An engine has to start somewhere. This one starts with a window.*

</div>

## Overview

**LTEngine** is a personal, tutorial-driven project exploring how a game engine works under the hood. It is written in **C++20** and currently targets **Windows**, using the native **Win32 API** rather than an existing game framework.

The repository is an **early prototype**, not a finished or production-ready game engine. It currently focuses on the application lifecycle, native window creation, and a basic message loop. Some parts may require fixes before the project builds and runs correctly.

The included demo application is named **Dogs May Cry**.

## What's implemented

- **Core foundation:** a simple `ltengine::Base` class for shared object structure.
- **Native window:** a `ltengine::Window` implementation using `RegisterClassEx`, `CreateWindowEx`, and `ShowWindow`.
- **Window configuration:** a nominal **1280 × 720** client area, with the title `Dogs May Cry`.
- **Application lifecycle:** `ltengine::Game` creates and destroys the window.
- **Message processing:** a Win32 loop using `PeekMessage`, `TranslateMessage`, and `DispatchMessage`, with `WM_QUIT` handling.

**Not implemented yet:** graphics rendering, scenes, entities, physics, audio, a dedicated input system, an editor, or asset management. Although C# was mentioned in the project's original description, the current repository contains **C++ code only**; there is no C# scripting layer yet.

## Project structure

```text
LTEngine/
├── Game/
│   └── main.cpp                       # Demo entry point
├── LTEngine/
│   ├── Include/LTEngine/
│   │   ├── Core/                      # Base types and declarations
│   │   ├── Game/                      # Game interface
│   │   └── Window/                    # Window interface
│   └── Source/LTEngine/
│       ├── Core/                      # Base implementation
│       ├── Game/                      # Game lifecycle and Win32 loop
│       └── Window/Win32/              # Native window implementation
├── Dogs May Cry - LTEngine.slnx       # Visual Studio solution
└── Dogs May Cry - LTEngine.vcxproj    # MSVC C++ project
```

The repository also currently contains `Bin/` and `Intermediate/` build-output directories.

## Getting started

### Requirements

- **Windows**
- **Visual Studio** with the **Desktop development with C++** workload
- **MSVC** with C++20 support
- **Windows 10 SDK**
- The project's configured **`v145` platform toolset**, or an installed toolset selected by retargeting the project

### Build and run

1. Clone the repository:

   ```bash
   git clone https://github.com/tihonovka/LTEngine.git
   cd LTEngine
   ```

2. Open **`Dogs May Cry - LTEngine.slnx`** in a Visual Studio version that supports `.slnx` solutions.
3. Select **`Debug`** and **`x64`**. The current project explicitly configures its engine include paths for this combination.
4. Install the required platform toolset, or retarget the project to a compatible installed one.
5. Fix any outstanding source issues listed below, then build and run the project from Visual Studio.

If the executable runs as intended, the demo should open a native Windows window titled **Dogs May Cry**. There is no game scene or rendering pipeline at this stage.

> **Build status:** This README documents the checked-in source; a clean build has not been independently verified. Do not assume every configuration works out of the box.

## Minimal entry point

The demo currently creates a `Game` instance and starts the message loop:

```cpp
#include <LTEngine/Window/All.h>

int main()
{
    ltengine::Game game{};
    game.run();
    return 0;
}
```

The example above normalizes the include directive by removing an extra space present in the checked-in `Game/main.cpp`.

## Known limitations

- **Compilation needs attention:** `Game/main.cpp` has a trailing space inside an `#include` header name, and the Win32 window procedure calls `PostQuitMessage()` without the required exit-code argument. These should be corrected before attempting a clean build.
- **Windows only:** window creation and the main loop depend directly on Win32.
- **Configuration-specific paths:** the engine include directories are explicitly set for the `Debug | x64` configuration in the project file.
- **No rendering yet:** a successful launch produces a native window, not a playable game.
- **Experimental architecture:** APIs and folder structure may change as the project grows.

## Roadmap

These are possible next steps, **not features currently available**:

- [ ] Fix build errors and verify a clean `x64` Debug build
- [ ] Improve window lifecycle, cleanup, and error handling
- [ ] Add frame timing and a real update loop
- [ ] Implement keyboard and mouse input
- [ ] Introduce a graphics backend and render loop
- [ ] Add basic entities, scenes, and resource management
- [ ] Explore scripting support, potentially including C#

## About this project

LTEngine is a **learning and experimentation repository** developed through tutorials, research, and hands-on implementation. The goal is to better understand engine architecture and low-level Windows programming by building the pieces directly.

Created by [**tihonovka**](https://github.com/tihonovka).

## License

No license file is currently included in this repository. Refer to the repository owner for reuse or distribution permissions.
