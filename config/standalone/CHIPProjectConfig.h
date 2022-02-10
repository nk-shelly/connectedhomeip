/*
 *
 *    Copyright (c) 2020-2022 Project CHIP Authors
 *    Copyright (c) 2016-2017 Nest Labs, Inc.
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

/**
 *    @file
 *      CHIP project configuration for standalone builds on Linux and OS X.
 *
 */
#ifndef CHIPPROJECTCONFIG_H
#define CHIPPROJECTCONFIG_H

#define CHIP_CONFIG_ENABLE_EPHEMERAL_UDP_PORT 1

#define CHIP_CONFIG_EVENT_LOGGING_NUM_EXTERNAL_CALLBACKS 2

#define CHIP_CONFIG_EVENT_LOGGING_EXTERNAL_EVENT_SUPPORT 1

// Uncomment this for a large Tunnel MTU.
//#define CHIP_CONFIG_TUNNEL_INTERFACE_MTU                           (9000)

// Enable support functions for parsing command-line arguments
#define CHIP_CONFIG_ENABLE_ARG_PARSER 1

//  Enable use of test setup parameters for testing purposes only.
//
//    WARNING: This option makes it possible to circumvent basic chip security functionality.
//    Because of this it SHOULD NEVER BE ENABLED IN PRODUCTION BUILDS.
//
#define CHIP_DEVICE_CONFIG_ENABLE_TEST_SETUP_PARAMS 1

// Enable reading DRBG seed data from /dev/(u)random.
// This is needed for test applications and the CHIP device manager to function
// properly when CHIP_CONFIG_RNG_IMPLEMENTATION_CHIPDRBG is enabled.
#define CHIP_CONFIG_DEV_RANDOM_DRBG_SEED 1

// For convenience, Chip Security Test Mode can be enabled and the
// requirement for authentication in various protocols can be disabled.
//
//    WARNING: These options make it possible to circumvent basic Chip security functionality,
//    including message encryption. Because of this they MUST NEVER BE ENABLED IN PRODUCTION BUILDS.
//
//    To build with this flag, pass 'treat_warnings_as_errors=false' to gn/ninja.
//
#define CHIP_CONFIG_SECURITY_TEST_MODE 0
#define CHIP_CONFIG_REQUIRE_AUTH 1

#define CHIP_CONFIG_ENABLE_UPDATE 1

#define CHIP_SYSTEM_CONFIG_PACKETBUFFER_POOL_SIZE 0

#define CHIP_CONFIG_DATA_MANAGEMENT_CLIENT_EXPERIMENTAL 1

#ifndef CHIP_DEVICE_CONFIG_DYNAMIC_ENDPOINT_COUNT
#define CHIP_DEVICE_CONFIG_DYNAMIC_ENDPOINT_COUNT 4
#endif

//
// Default of 8 ECs is not sufficient for some of the unit tests
// that try to validate multiple simultaneous interactions.
//
#define CHIP_CONFIG_MAX_EXCHANGE_CONTEXTS 16

//
// Set this to a value greater than the value for CHIP_IM_MAX_NUM_READ_HANDLER
// to ensure some of the tests for validating resource exhaustion and heap allocation
// pass correctly.
//
// TODO: Once we fix ReadClients to be heap allocated, we no longer need this override.
//
#define CHIP_IM_MAX_NUM_READ_CLIENT 6

#define CONFIG_IM_BUILD_FOR_UNIT_TEST 1

#endif /* CHIPPROJECTCONFIG_H */
