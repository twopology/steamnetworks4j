package org.twopology.steamnetworks4j;

public interface SteamScreenshotsCallback {

	default void onScreenshotReady(SteamScreenshotHandle local, SteamResult result) {
	}

	default void onScreenshotRequested() {
	}

}
