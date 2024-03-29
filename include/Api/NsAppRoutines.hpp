#pragma once

#include <ArxContainer.h>

namespace NsAppRoutines {

	/**
	 * @brief A class to allow many tasks to take place at once, and be added or removed easily.
	 * All data is maintained privately, in a single implementation file.
	 *
	 * The default implementations call `DEBUG_PRINTLN()` to remind about missing overrides.
	 */
	class AppRoutine {
	public:
		/** @brief  Called when this routine starts. */
		virtual void setup();

		/** @brief  Called in `loop()` after this routine has started. */
		virtual void loop();

		/**
		 * @brief  Called when this routine has been requested to be removed
		 * from the list of currently active routines.
		 */
		virtual void out();

	};

	/**
	 * @brief A class to allow many tasks to take place at once, and be added or removed easily.
	 * All data is maintained privately, in a single implementation file.
	 *
	 * The default implementations call `DEBUG_PRINTLN()` to remind about missing overrides.
	 */
	template <typename ServiceCallbackT>
	class AppRoutineWithServices : public NsAppRoutines::AppRoutine {
	protected:
		arx::vector<ServiceCallbackT *> callbacks;
	};

	enum class AppRoutineAdditionError {
		NO_ERROR,
		ROUTINE_ALREADY_EXISTS,
	};

#pragma region // Methods to manage routine collections.
	/**
	 * @brief Attempts to add a routine of the given type, returning
	 * `NsAppRoutines::AppRoutineAdditionError::ROUTINE_ALREADY_EXISTS` if it was already added.
	 * Otherwise, the routine is added and `NsAppRoutines::AppRoutineAdditionError::NO_ERROR` is returned.
	 */
	template <class RoutineT>
	NsAppRoutines::AppRoutineAdditionError addRoutine();

	/** @brief Attempts to remove a routine, then tell if it was successful. */
	template <class RoutineT>
	bool removeRoutine();
#pragma endregion

}
