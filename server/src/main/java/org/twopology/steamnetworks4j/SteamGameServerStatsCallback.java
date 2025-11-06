package org.twopology.steamnetworks4j;

public interface SteamGameServerStatsCallback {

    default void onStatsReceived(SteamResult result, SteamID steamIDUser) {
    }

    default void onStatsStored(SteamResult result, SteamID steamIDUser) {
    }

    default void onStatsUnloaded(SteamID steamIDUser) {
    }

}
