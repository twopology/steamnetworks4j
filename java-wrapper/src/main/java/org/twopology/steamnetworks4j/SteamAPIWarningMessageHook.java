package org.twopology.steamnetworks4j;

public interface SteamAPIWarningMessageHook {
	void onWarningMessage(int severity, String message);
}
