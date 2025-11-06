# Steam Networks for Java

A modern Java 21 wrapper for the Steam API with comprehensive networking support.

[![Build Status](https://github.com/twopology/steamnetworks4j/workflows/Build%20and%20Test/badge.svg)](https://github.com/twopology/steamnetworks4j/actions)
[![GitHub Packages](https://img.shields.io/badge/GitHub%20Packages-0.0.7-blue)](https://github.com/twopology/steamnetworks4j/packages)

## Features

- **Modern Java 21** - Built with the latest LTS Java version
- **Steam Networking Sockets** - Full support for Steam's modern P2P networking API
- **Cross-Platform** - Native libraries included for Windows, macOS, and Linux
- **Zero Configuration** - Native libraries packaged in JAR for easy deployment
- **GitHub Packages** - Easy distribution and consumption

## Quick Start

### Maven Dependency

```xml
<dependency>
    <groupId>org.twopology</groupId>
    <artifactId>steamnetworks4j</artifactId>
    <version>0.0.7</version>
</dependency>
```

### Repository Configuration

```xml
<repositories>
    <repository>
        <id>github</id>
        <url>https://maven.pkg.github.com/twopology/steamnetworks4j</url>
    </repository>
</repositories>
```

### Basic Usage

```java
import org.twopology.steamnetworks4j.*;

// Initialize Steam API
SteamAPI.init();

// Create networking interface
SteamNetworkingSockets networking = new SteamNetworkingSockets(callback);

// Connect to another player
int connection = networking.connectP2P(targetSteamID, 0);

// Send a message
byte[] data = "Hello, Steam!".getBytes();
networking.sendMessageToConnection(connection, data, 
    SteamNetworkingSockets.SEND_FLAG_RELIABLE);
```

## Documentation

- [Steam Networking Usage Guide](STEAM_NETWORKING_USAGE.md) - Complete API documentation with examples
- [GitHub Packages Setup](GITHUB_PACKAGES_SETUP.md) - Publishing and consumption guide
- [Linux Binaries Plan](LINUX_BINARIES_PLAN.md) - Native library implementation details

## Key Differences from steamnetworks4j

This is **not** a drop-in replacement for the original steamnetworks4j library:

- **Package Name**: `org.twopology.steamnetworks4j` (not `com.codedisaster.steamworks`)
- **Java Version**: Requires Java 21+ (not Java 8+)
- **Artifact Name**: `steamnetworks4j` (not `steamnetworks4j`)
- **Focus**: Modern networking features with latest Java capabilities

## Requirements

- **Java 21+** - Latest LTS version required
- **Steam Client** - Must be running for API access
- **Steam Account** - Required for networking features

## Building

```bash
# Build with Java 21
mvn clean compile

# Package with native libraries
mvn clean package

# Install to local repository
mvn clean install
```

## Modules

- **steamnetworks4j** - Main library with Steam API wrapper
- **steamnetworks4j-server** - Server-side Steam API components
- **steamnetworks4j-gdx** - LibGDX integration
- **steamnetworks4j-lwjgl3** - LWJGL3 integration
- **steamnetworks4j-tests** - Test applications and examples

## License

MIT License - see [LICENSE](LICENSE) file for details.

## Acknowledgments

Based on the excellent work by Daniel Ludwig ([code-disaster/steamnetworks4j](https://github.com/code-disaster/steamnetworks4j)) and Tyler Hasman's networking additions.

## Contributing

Contributions are welcome! Please feel free to submit issues and pull requests.

## Support

- [GitHub Issues](https://github.com/twopology/steamnetworks4j/issues) - Bug reports and feature requests
- [GitHub Discussions](https://github.com/twopology/steamnetworks4j/discussions) - Community support and questions