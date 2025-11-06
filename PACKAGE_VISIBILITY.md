# Making GitHub Packages Public

## Current Issue
GitHub Packages are private by default, even for public repositories. This requires authentication to download, which is inconvenient for users.

## How to Make Packages Public

### Option 1: Change Package Visibility (Recommended)
After the package is published, you can make it public:

1. Go to `https://github.com/twopology/steamnetworks4j/packages`
2. Click on the package name (e.g., `steamnetworks4j`)
3. Go to "Package settings" (gear icon)
4. Scroll down to "Danger Zone"
5. Click "Change visibility"
6. Select "Public"
7. Confirm the change

### Option 2: Repository Settings
Ensure your repository settings allow public packages:

1. Go to repository Settings
2. Scroll to "Features" section
3. Ensure "Packages" is enabled
4. Check package visibility settings

## Benefits of Public Packages

✅ **No Authentication Required** - Users can download without GitHub tokens
✅ **Easier Integration** - Standard Maven dependency without special repository configuration
✅ **Better Discoverability** - Packages appear in GitHub's package registry
✅ **Simpler Documentation** - No need to explain authentication setup

## After Making Public

Once packages are public, users can simply add:

```xml
<dependency>
    <groupId>org.twopology</groupId>
    <artifactId>steamnetworks4j</artifactId>
    <version>4</version>
</dependency>
```

Without needing:
- GitHub Personal Access Tokens
- Special repository configuration
- Authentication setup

## Alternative: Maven Central

For maximum accessibility, consider publishing to Maven Central:
- No GitHub account required for users
- Standard Maven repository
- Better for open-source libraries

The current POM already has a `central` profile configured for this.

## Current Status

After v0.0.9 is published, manually change the package visibility to public for the best user experience.