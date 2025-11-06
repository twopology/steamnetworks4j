package org.twopology.steamnetworks4j;

/**
 * See the steamnetworks4j-gdx and steamnetworks4j-lwjgl3 modules for sample
 * implementations of this interface.
 * <p>
 * The default implementation does nothing. This can be used to bypass
 * library loading altogether, and let the calling application manage
 * this task itself.
 */
public interface SteamLibraryLoader {

	default void setLibraryPath(String libraryPath) {

	}

	default boolean loadLibrary(String libraryName) {
		return true;
	}

}
