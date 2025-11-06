# GitHub Packages Setup

This repository is configured to publish to GitHub Packages for easy distribution of Steam Networks for Java.

## Repository Information

- **Group ID**: `org.twopology`
- **Artifact ID**: `steamnetworks4j`
- **Version**: `0.0.3`
- **GitHub Packages URL**: `https://maven.pkg.github.com/twopology/steamnetworks4j`

## Publishing

### Automatic Publishing (GitHub Actions)

The repository includes GitHub Actions workflows for automatic publishing:

1. **Manual Trigger**: Use the "Publish to GitHub Packages" workflow in the Actions tab
2. **Tag-based**: Push a tag starting with `v` (e.g., `v0.0.1`) to trigger automatic publishing

### Manual Publishing

To publish manually from your local machine:

```bash
# Build and publish to GitHub Packages
mvn clean deploy -DnoLibs -Pgithub
```

**Requirements:**
- GitHub Personal Access Token with `write:packages` permission
- Maven settings.xml configured with GitHub credentials

### Maven Settings Configuration

Create or update `~/.m2/settings.xml`:

```xml
<settings>
  <servers>
    <server>
      <id>github</id>
      <username>YOUR_GITHUB_USERNAME</username>
      <password>YOUR_GITHUB_TOKEN</password>
    </server>
  </servers>
</settings>
```

## Using the Package

### Maven Dependency

Add to your `pom.xml`:

```xml
<dependency>
    <groupId>org.twopology</groupId>
    <artifactId>steamnetworks4j</artifactId>
    <version>0.0.3</version>
</dependency>
```

### Repository Configuration

Add the GitHub Packages repository to your `pom.xml`:

```xml
<repositories>
    <repository>
        <id>github</id>
        <url>https://maven.pkg.github.com/twopology/steamnetworks4j</url>
    </repository>
</repositories>
```

### Authentication for Consumers

Users consuming the package need to authenticate with GitHub Packages. Add to their `~/.m2/settings.xml`:

```xml
<settings>
  <servers>
    <server>
      <id>github</id>
      <username>THEIR_GITHUB_USERNAME</username>
      <password>THEIR_GITHUB_TOKEN</password>
    </server>
  </servers>
</settings>
```

## Features in This Fork

- **Steam Networking Sockets API**: Modern P2P networking with encryption and reliability
- **Windows Native Libraries**: Pre-built DLLs included in the JAR
- **Cross-Platform Support**: macOS and Linux natives also included

## Next Steps

1. Test local build and publishing
2. Add Linux native libraries for complete cross-platform support
3. Create comprehensive examples and documentation
4. Set up automated testing pipeline