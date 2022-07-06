/*
 *
 *    Copyright (c) 2019 Google LLC.
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

#include "AppEvent.h"
#include <app/clusters/door-lock-server/door-lock-server.h>
#include <chip_lock.h>
#include <lib/core/CHIPError.h>
#include <lib/support/logging/CHIPLogging.h>
#include <stdint.h>
#include <wiced_timer.h>

namespace CYW30739DoorLock {
namespace ResourceRanges {
// Used to size arrays
static constexpr uint16_t kMaxUsers                  = 10;
static constexpr uint8_t kMaxCredentialsPerUser      = 10;
static constexpr uint8_t kMaxWeekdaySchedulesPerUser = 10;
static constexpr uint8_t kMaxYeardaySchedulesPerUser = 10;
static constexpr uint8_t kMaxHolidaySchedules        = 10;
static constexpr uint8_t kMaxCredentialSize          = 8;

// Indices received for user/credential/schedules are 1-indexed
static constexpr uint8_t kStartIndexValue = 1;

static constexpr uint8_t kMaxCredentials = kMaxUsers * kMaxCredentialsPerUser;
} // namespace ResourceRanges

namespace LockInitParams {

struct LockParam
{
    // Read from zap attributes
    uint16_t numberOfUsers                  = 0;
    uint8_t numberOfCredentialsPerUser      = 0;
    uint8_t numberOfWeekdaySchedulesPerUser = 0;
    uint8_t numberOfYeardaySchedulesPerUser = 0;
    uint8_t numberOfHolidaySchedules        = 0;
};

class ParamBuilder
{
public:
    ParamBuilder & SetNumberOfUsers(uint16_t numberOfUsers)
    {
        lockParam_.numberOfUsers = numberOfUsers;
        return *this;
    }
    ParamBuilder & SetNumberOfCredentialsPerUser(uint8_t numberOfCredentialsPerUser)
    {
        lockParam_.numberOfCredentialsPerUser = numberOfCredentialsPerUser;
        return *this;
    }
    ParamBuilder & SetNumberOfWeekdaySchedulesPerUser(uint8_t numberOfWeekdaySchedulesPerUser)
    {
        lockParam_.numberOfWeekdaySchedulesPerUser = numberOfWeekdaySchedulesPerUser;
        return *this;
    }
    ParamBuilder & SetNumberOfYeardaySchedulesPerUser(uint8_t numberOfYeardaySchedulesPerUser)
    {
        lockParam_.numberOfYeardaySchedulesPerUser = numberOfYeardaySchedulesPerUser;
        return *this;
    }
    ParamBuilder & SetNumberOfHolidaySchedules(uint8_t numberOfHolidaySchedules)
    {
        lockParam_.numberOfHolidaySchedules = numberOfHolidaySchedules;
        return *this;
    }
    LockParam GetLockParam() { return lockParam_; }

private:
    LockParam lockParam_;
};

} // namespace LockInitParams
} // namespace CYW30739DoorLock

using namespace ::chip;
using namespace CYW30739DoorLock::ResourceRanges;

class LockManager
{
public:
    enum Action_t
    {
        LOCK_ACTION = 0,
        UNLOCK_ACTION,

        INVALID_ACTION
    } Action;

    enum State_t
    {
        kState_LockInitiated = 0,
        kState_LockCompleted,
        kState_UnlockInitiated,
        kState_UnlockCompleted,
    } State;

    enum Actor_t
    {
        ACTOR_ZCL_CMD = 0,
        ACTOR_APP_CMD,
        ACTOR_BUTTON,
    } Actor;

    CHIP_ERROR Init(chip::app::DataModel::Nullable<chip::app::Clusters::DoorLock::DlLockState> state,
                    CYW30739DoorLock::LockInitParams::LockParam lockParam);
    bool NextState();
    bool IsActionInProgress();
    bool InitiateAction(int32_t aActor, Action_t aAction);

    typedef void (*Callback_fn_initiated)(Action_t, int32_t aActor);
    typedef void (*Callback_fn_completed)(Action_t);
    void SetCallbacks(Callback_fn_initiated aActionInitiated_CB, Callback_fn_completed aActionCompleted_CB);

    bool Lock(chip::EndpointId endpointId, const Optional<chip::ByteSpan> & pin, DlOperationError & err);
    bool Unlock(chip::EndpointId endpointId, const Optional<chip::ByteSpan> & pin, DlOperationError & err);

    bool GetUser(chip::EndpointId endpointId, uint16_t userIndex, EmberAfPluginDoorLockUserInfo & user);
    bool SetUser(chip::EndpointId endpointId, uint16_t userIndex, chip::FabricIndex creator, chip::FabricIndex modifier,
                 const chip::CharSpan & userName, uint32_t uniqueId, DlUserStatus userStatus, DlUserType usertype,
                 DlCredentialRule credentialRule, const DlCredential * credentials, size_t totalCredentials);

    bool GetCredential(chip::EndpointId endpointId, uint16_t credentialIndex, DlCredentialType credentialType,
                       EmberAfPluginDoorLockCredentialInfo & credential);

    bool SetCredential(chip::EndpointId endpointId, uint16_t credentialIndex, chip::FabricIndex creator, chip::FabricIndex modifier,
                       DlCredentialStatus credentialStatus, DlCredentialType credentialType, const chip::ByteSpan & credentialData);

    DlStatus GetWeekdaySchedule(chip::EndpointId endpointId, uint8_t weekdayIndex, uint16_t userIndex,
                                EmberAfPluginDoorLockWeekDaySchedule & schedule);

    DlStatus SetWeekdaySchedule(chip::EndpointId endpointId, uint8_t weekdayIndex, uint16_t userIndex, DlScheduleStatus status,
                                DlDaysMaskMap daysMask, uint8_t startHour, uint8_t startMinute, uint8_t endHour, uint8_t endMinute);

    DlStatus GetYeardaySchedule(chip::EndpointId endpointId, uint8_t yearDayIndex, uint16_t userIndex,
                                EmberAfPluginDoorLockYearDaySchedule & schedule);

    DlStatus SetYeardaySchedule(chip::EndpointId endpointId, uint8_t yearDayIndex, uint16_t userIndex, DlScheduleStatus status,
                                uint32_t localStartTime, uint32_t localEndTime);

    DlStatus GetHolidaySchedule(chip::EndpointId endpointId, uint8_t holidayIndex, EmberAfPluginDoorLockHolidaySchedule & schedule);

    DlStatus SetHolidaySchedule(chip::EndpointId endpointId, uint8_t holidayIndex, DlScheduleStatus status, uint32_t localStartTime,
                                uint32_t localEndTime, DlOperatingMode operatingMode);

    bool IsValidUserIndex(uint16_t userIndex);
    bool IsValidCredentialIndex(uint16_t credentialIndex, DlCredentialType type);
    bool IsValidWeekdayScheduleIndex(uint8_t scheduleIndex);
    bool IsValidYeardayScheduleIndex(uint8_t scheduleIndex);
    bool IsValidHolidayScheduleIndex(uint8_t scheduleIndex);

    bool setLockState(chip::EndpointId endpointId, DlLockState lockState, const Optional<chip::ByteSpan> & pin,
                      DlOperationError & err);
    const char * lockStateToString(DlLockState lockState) const;

    bool ReadConfigValues();

private:
    friend LockManager & LockMgr();
    chip::EndpointId mEndpointId;
    State_t mState;

    Callback_fn_initiated mActionInitiated_CB;
    Callback_fn_completed mActionCompleted_CB;

    void CancelTimer(void);
    void StartTimer(uint32_t aTimeoutMs);

    static void TimerEventHandler(WICED_TIMER_PARAM_TYPE cb_params);
    static int ActuatorMovementTimerEventHandler(void * aEvent);

    EmberAfPluginDoorLockUserInfo mLockUsers[kMaxUsers];
    EmberAfPluginDoorLockCredentialInfo mLockCredentials[kMaxCredentials];
    EmberAfPluginDoorLockWeekDaySchedule mWeekdaySchedule[kMaxUsers][kMaxWeekdaySchedulesPerUser];
    EmberAfPluginDoorLockYearDaySchedule mYeardaySchedule[kMaxUsers][kMaxYeardaySchedulesPerUser];
    EmberAfPluginDoorLockHolidaySchedule mHolidaySchedule[kMaxHolidaySchedules];

    char mUserNames[ArraySize(mLockUsers)][DOOR_LOCK_MAX_USER_NAME_SIZE];
    uint8_t mCredentialData[kMaxCredentials][kMaxCredentialSize];
    DlCredential mCredentials[kMaxUsers][kMaxCredentialsPerUser];

    static LockManager sLock;
    CYW30739DoorLock::LockInitParams::LockParam LockParams;
};

inline LockManager & LockMgr()
{
    return LockManager::sLock;
}
