# Steam Networks for Java - Usage Guide

This modern Java library provides support for Steam's networking API (`SteamNetworkingSockets`) which enables reliable, encrypted P2P connections between Steam users.

## Key Features Added

### SteamNetworkingSockets API
- **P2P Connection Management**: Create and manage peer-to-peer connections
- **Message Sending**: Send reliable/unreliable messages with various flags
- **Connection Status Callbacks**: Get notified of connection state changes
- **Poll Groups**: Efficiently handle multiple connections
- **Authentication & Relay**: Support for Steam's relay network and authentication

### New Classes
- `SteamNetworkingSockets` - Main API interface
- `SteamNetworkingSocketsCallback` - Callback interface for connection events
- `SteamNetworkingMessage` - Message container for received data
- `SteamNetworkingAvailability` - Enum for network service availability

## Basic Usage

### 1. Initialize the Networking Interface

```java
import org.twopology.steamnetworks4j.*;

// Implement the callback interface
SteamNetworkingSocketsCallback callback = new SteamNetworkingSocketsCallback() {
    @Override
    public void onConnectionStatusChanged(int connectionHandle, long steamID, 
                                        int connectionState, int prevState) {
        ConnectionState state = ConnectionState.fromValue(connectionState);
        System.out.println("Connection " + connectionHandle + " changed to: " + state);
    }
};

// Create the networking interface
SteamNetworkingSockets networking = new SteamNetworkingSockets(callback);
```

### 2. Create a Listen Socket (Server)

```java
// Create a listen socket for P2P connections
int listenSocket = networking.createListenSocketP2P(0); // 0 virtual ports
```

### 3. Connect to Another Player (Client)

```java
// Connect to another Steam user
long targetSteamID = 76561198000000000L; // Target player's Steam ID
int connection = networking.connectP2P(targetSteamID, 0);
```

### 4. Accept Incoming Connections

```java
// In your callback, when you receive a connection request:
public void onConnectionStatusChanged(int connectionHandle, long steamID, 
                                    int connectionState, int prevState) {
    if (ConnectionState.fromValue(connectionState) == ConnectionState.CONNECTING) {
        // Accept the connection
        SteamResult result = networking.acceptConnection(connectionHandle);
        if (result == SteamResult.OK) {
            System.out.println("Connection accepted!");
        }
    }
}
```

### 5. Send Messages

```java
// Send a reliable message
byte[] messageData = "Hello, Steam!".getBytes();
SteamResult result = networking.sendMessageToConnection(
    connectionHandle, 
    messageData, 
    SteamNetworkingSockets.SEND_FLAG_RELIABLE
);

// Flush messages to ensure immediate sending
networking.flushMessages(connectionHandle);
```

### 6. Receive Messages

```java
// Create message array to receive into
SteamNetworkingMessage[] messages = new SteamNetworkingMessage[10];

// Receive messages from a specific connection
int numReceived = networking.receiveMessagesOnConnection(connectionHandle, messages);

for (int i = 0; i < numReceived; i++) {
    SteamNetworkingMessage msg = messages[i];
    System.out.println("Received: " + new String(msg.payload));
}
```

### 7. Using Poll Groups (Multiple Connections)

```java
// Create a poll group for efficient multi-connection handling
int pollGroup = networking.createPollGroup();

// Add connections to the poll group
networking.setConnectionPollGroup(connection1, pollGroup);
networking.setConnectionPollGroup(connection2, pollGroup);

// Receive messages from any connection in the group
int numReceived = networking.receiveMessagesOnPollGroup(pollGroup, messages);
```

## Send Flags

- `SEND_FLAG_UNRELIABLE` (0) - Fast, no delivery guarantee
- `SEND_FLAG_NO_NAGLE` (1) - Disable Nagle's algorithm
- `SEND_FLAG_NO_DELAY` (4) - Send immediately or drop
- `SEND_FLAG_RELIABLE` (8) - Guaranteed delivery
- `SEND_FLAG_AUTO_RESTART` (32) - Auto-restart broken connections

## Connection States

- `NONE` - Error or closed connection
- `CONNECTING` - Connection attempt in progress
- `FINDING_ROUTE` - Finding network route
- `CONNECTED` - Stable connection established
- `CLOSED_BY_PEER` - Peer closed the connection
- `PROBLEM_DETECTED_LOCALLY` - Local network issue detected

## Authentication & Relay Network

```java
// Initialize authentication (required for some features)
SteamNetworkingAvailability authStatus = networking.initAuthentication();

// Initialize relay network access (for NAT traversal)
networking.initRelayNetworkAccess();

// Check relay network status
SteamNetworkingAvailability relayStatus = networking.getRelayNetworkStatus();
```

## Cleanup

```java
// Close connections
networking.closeConnection(connectionHandle, 0, false);

// Close listen sockets
networking.closeListenSocket(listenSocket);

// Destroy poll groups
networking.destroyPollGroup(pollGroup);
```

This modern networking API provides better performance, security, and reliability compared to the older P2P networking functions.