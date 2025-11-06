import org.twopology.steamnetworks4j.*;

/**
 * Basic example of Steam Networking Sockets usage
 */
public class BasicNetworking {
    
    public static void main(String[] args) {
        // Initialize Steam API
        if (!SteamAPI.init()) {
            System.err.println("Failed to initialize Steam API");
            return;
        }
        
        // Create networking callback
        SteamNetworkingSocketsCallback callback = new SteamNetworkingSocketsCallback() {
            @Override
            public void onConnectionStatusChanged(int connectionHandle, long steamID, 
                                                int connectionState, int prevState) {
                ConnectionState state = ConnectionState.fromValue(connectionState);
                System.out.println("Connection " + connectionHandle + " changed to: " + state);
                
                if (state == ConnectionState.CONNECTED) {
                    System.out.println("Successfully connected to " + steamID);
                    
                    // Send a test message
                    sendTestMessage(connectionHandle);
                }
            }
        };
        
        // Create networking interface
        SteamNetworkingSockets networking = new SteamNetworkingSockets(callback);
        
        // Initialize authentication and relay network
        networking.initAuthentication();
        networking.initRelayNetworkAccess();
        
        // Example: Create a listen socket (server mode)
        int listenSocket = networking.createListenSocketP2P(0);
        System.out.println("Created listen socket: " + listenSocket);
        
        // Example: Connect to another player (client mode)
        // Replace with actual Steam ID
        // long targetSteamID = 76561198000000000L;
        // int connection = networking.connectP2P(targetSteamID, 0);
        // System.out.println("Connecting to " + targetSteamID + ", connection: " + connection);
        
        // Main loop (simplified)
        System.out.println("Steam networking initialized. Press Ctrl+C to exit.");
        
        try {
            while (true) {
                // Process Steam callbacks
                SteamAPI.runCallbacks();
                
                // Your game logic here
                Thread.sleep(16); // ~60 FPS
            }
        } catch (InterruptedException e) {
            System.out.println("Interrupted, shutting down...");
        } finally {
            // Cleanup
            networking.closeListenSocket(listenSocket);
            SteamAPI.shutdown();
        }
    }
    
    private static void sendTestMessage(int connectionHandle) {
        try {
            SteamNetworkingSockets networking = getCurrentNetworking(); // You'd store this reference
            
            String message = "Hello from Steam Networks for Java!";
            byte[] data = message.getBytes("UTF-8");
            
            SteamResult result = networking.sendMessageToConnection(
                connectionHandle, 
                data, 
                SteamNetworkingSockets.SEND_FLAG_RELIABLE
            );
            
            if (result == SteamResult.OK) {
                System.out.println("Message sent successfully");
                networking.flushMessages(connectionHandle);
            } else {
                System.err.println("Failed to send message: " + result);
            }
        } catch (Exception e) {
            System.err.println("Error sending message: " + e.getMessage());
        }
    }
    
    // In a real application, you'd store the networking instance
    private static SteamNetworkingSockets getCurrentNetworking() {
        return null; // Placeholder
    }
}