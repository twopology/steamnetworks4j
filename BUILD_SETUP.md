# Building Steam Networks for Java - Setup Guide

## Prerequisites

### 1. System Dependencies

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install -y premake4 build-essential
```

**Other Linux distributions:**
- Install `premake4` and `build-essential` (or equivalent)
- Ensure you have GCC/G++ compiler

### 2. Steam SDK Required

You need the official Steam SDK from Valve. This is **not** included in this repository due to licensing restrictions.

#### Getting the Steam SDK

1. **Steamworks Partner Account Required**
   - You need a Steamworks developer account
   - Go to [Steamworks Partner](https://partner.steamgames.com/)

2. **Download the SDK**
   - Navigate to Downloads section
   - Download `steamworks_sdk.zip`
   - Current supported version: 1.59+

3. **Extract and Setup**
   ```bash
   # Extract the downloaded SDK
   unzip steamworks_sdk.zip
   
   # Copy the sdk folder to your project root
   cp -r steamworks_sdk/sdk /path/to/steamnetworks4j/
   ```

#### Expected Directory Structure

After setup, you should have:

```
steamnetworks4j/
├── sdk/
│   ├── public/
│   │   └── steam/
│   │       ├── steam_api.h
│   │       ├── steam_api_common.h
│   │       ├── isteamnetworkingsockets.h
│   │       └── lib/
│   │           └── linux64/
│   │               └── libsdkencryptedappticket.a
│   └── redistributable_bin/
│       ├── linux64/
│       │   └── libsteam_api.so
│       ├── osx/
│       │   └── libsteam_api.dylib
│       └── win64/
│           ├── steam_api64.dll
│           └── steam_api64.lib
├── build-natives/
└── java-wrapper/
```

## Building Native Libraries

### Linux Build

```bash
cd build-natives
./build-linux.sh
```

This will:
1. Generate makefiles using premake4
2. Compile the JNI wrapper libraries
3. Link against Steam SDK
4. Copy resulting `.so` files to Java resources

### Expected Output

After successful build:
- `libsteamworks4j.so` → `java-wrapper/src/main/resources/`
- `libsteamworks4j-server.so` → `server/src/main/resources/`
- `libsteamworks4j-encryptedappticket.so` → `server/src/main/resources/`

### macOS Build

```bash
cd build-natives
./build-osx.sh
```

### Windows Build

```bash
cd build-natives
build-win.bat
```

## Troubleshooting

### Common Issues

**1. `premake4: command not found`**
```bash
sudo apt install premake4
```

**2. `steam_api.h: No such file or directory`**
- Steam SDK not properly installed
- Check that `sdk/public/steam/steam_api.h` exists

**3. `cannot find -lsteam_api`**
- Steam API library missing
- Check that `sdk/redistributable_bin/linux64/libsteam_api.so` exists

**4. Permission denied on build scripts**
```bash
chmod +x build-natives/*.sh
```

### Verification

After building, verify the libraries:

```bash
# Check if libraries were created
ls -la java-wrapper/src/main/resources/*.so
ls -la server/src/main/resources/*.so

# Check library dependencies
ldd java-wrapper/src/main/resources/libsteamworks4j.so
```

You should see `libsteam_api.so` as a dependency.

## Alternative: Use Pre-built Libraries

If you can't build from source, you can:

1. Use the existing libraries in the repository (may be outdated)
2. Download pre-built libraries from releases (when available)
3. Build on a different machine and copy the `.so` files

## Integration with Your Game

Once built, your game needs:

1. **This JAR** - Contains `libsteamworks4j.so` (JNI wrapper)
2. **Steam SDK** - `libsteam_api.so` (official Steam library)
3. **Steam Client** - Running on the target machine

The JAR will automatically extract and load `libsteamworks4j.so`, but you need to ensure `libsteam_api.so` is available in your game's library path.

## Development Workflow

1. Make changes to Java code → No rebuild needed
2. Make changes to C++ native code → Rebuild required
3. Update to new Steam SDK → Rebuild required

```bash
# Quick rebuild after native changes
cd build-natives
make clean
make config=release64
```