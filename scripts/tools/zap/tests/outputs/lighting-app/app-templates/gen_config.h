/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
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

// THIS FILE IS GENERATED BY ZAP

// Prevent multiple inclusion
#pragma once

// User options for plugin Binding Table Library
#define EMBER_BINDING_TABLE_SIZE 10

/**** Network Section ****/
#define EMBER_SUPPORTED_NETWORKS (1)

#define EMBER_APS_UNICAST_MESSAGE_COUNT 10

/**** Cluster endpoint counts ****/
#define EMBER_AF_IDENTIFY_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_GROUPS_CLUSTER_SERVER_ENDPOINT_COUNT (2)
#define EMBER_AF_ON_OFF_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_LEVEL_CONTROL_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_DESCRIPTOR_CLUSTER_SERVER_ENDPOINT_COUNT (2)
#define EMBER_AF_ACCESS_CONTROL_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_BASIC_INFORMATION_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_OTA_SOFTWARE_UPDATE_PROVIDER_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_OTA_SOFTWARE_UPDATE_REQUESTOR_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_LOCALIZATION_CONFIGURATION_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_TIME_FORMAT_LOCALIZATION_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_GENERAL_COMMISSIONING_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_NETWORK_COMMISSIONING_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_DIAGNOSTIC_LOGS_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_GENERAL_DIAGNOSTICS_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_SOFTWARE_DIAGNOSTICS_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_THREAD_NETWORK_DIAGNOSTICS_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_WIFI_NETWORK_DIAGNOSTICS_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_ETHERNET_NETWORK_DIAGNOSTICS_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_SWITCH_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_ADMINISTRATOR_COMMISSIONING_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_OPERATIONAL_CREDENTIALS_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_GROUP_KEY_MANAGEMENT_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_FIXED_LABEL_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_USER_LABEL_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_COLOR_CONTROL_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_OCCUPANCY_SENSING_CLUSTER_SERVER_ENDPOINT_COUNT (1)

/**** Cluster Plugins ****/

// Use this macro to check if the server side of the Identify cluster is included
#define ZCL_USING_IDENTIFY_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_IDENTIFY_SERVER
#define EMBER_AF_PLUGIN_IDENTIFY

// Use this macro to check if the server side of the Groups cluster is included
#define ZCL_USING_GROUPS_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_GROUPS_SERVER
#define EMBER_AF_PLUGIN_GROUPS

// Use this macro to check if the server side of the On/Off cluster is included
#define ZCL_USING_ON_OFF_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_ON_OFF_SERVER
#define EMBER_AF_PLUGIN_ON_OFF

// Use this macro to check if the server side of the Level Control cluster is included
#define ZCL_USING_LEVEL_CONTROL_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_LEVEL_CONTROL_SERVER
#define EMBER_AF_PLUGIN_LEVEL_CONTROL
// User options for server plugin Level Control
#define EMBER_AF_PLUGIN_LEVEL_CONTROL_MAXIMUM_LEVEL 254
#define EMBER_AF_PLUGIN_LEVEL_CONTROL_MINIMUM_LEVEL 0
#define EMBER_AF_PLUGIN_LEVEL_CONTROL_RATE 0

// Use this macro to check if the server side of the Descriptor cluster is included
#define ZCL_USING_DESCRIPTOR_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_DESCRIPTOR_SERVER
#define EMBER_AF_PLUGIN_DESCRIPTOR

// Use this macro to check if the server side of the Access Control cluster is included
#define ZCL_USING_ACCESS_CONTROL_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_ACCESS_CONTROL_SERVER
#define EMBER_AF_PLUGIN_ACCESS_CONTROL

// Use this macro to check if the server side of the Basic Information cluster is included
#define ZCL_USING_BASIC_INFORMATION_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_BASIC_INFORMATION_SERVER
#define EMBER_AF_PLUGIN_BASIC_INFORMATION

// Use this macro to check if the client side of the OTA Software Update Provider cluster is included
#define ZCL_USING_OTA_SOFTWARE_UPDATE_PROVIDER_CLUSTER_CLIENT
#define EMBER_AF_PLUGIN_OTA_SOFTWARE_UPDATE_PROVIDER_CLIENT

// Use this macro to check if the server side of the OTA Software Update Requestor cluster is included
#define ZCL_USING_OTA_SOFTWARE_UPDATE_REQUESTOR_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_OTA_SOFTWARE_UPDATE_REQUESTOR_SERVER
#define EMBER_AF_PLUGIN_OTA_SOFTWARE_UPDATE_REQUESTOR

// Use this macro to check if the server side of the Localization Configuration cluster is included
#define ZCL_USING_LOCALIZATION_CONFIGURATION_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_LOCALIZATION_CONFIGURATION_SERVER
#define EMBER_AF_PLUGIN_LOCALIZATION_CONFIGURATION

// Use this macro to check if the server side of the Time Format Localization cluster is included
#define ZCL_USING_TIME_FORMAT_LOCALIZATION_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_TIME_FORMAT_LOCALIZATION_SERVER
#define EMBER_AF_PLUGIN_TIME_FORMAT_LOCALIZATION

// Use this macro to check if the server side of the General Commissioning cluster is included
#define ZCL_USING_GENERAL_COMMISSIONING_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_GENERAL_COMMISSIONING_SERVER
#define EMBER_AF_PLUGIN_GENERAL_COMMISSIONING

// Use this macro to check if the server side of the Network Commissioning cluster is included
#define ZCL_USING_NETWORK_COMMISSIONING_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_NETWORK_COMMISSIONING_SERVER
#define EMBER_AF_PLUGIN_NETWORK_COMMISSIONING

// Use this macro to check if the server side of the Diagnostic Logs cluster is included
#define ZCL_USING_DIAGNOSTIC_LOGS_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_DIAGNOSTIC_LOGS_SERVER
#define EMBER_AF_PLUGIN_DIAGNOSTIC_LOGS

// Use this macro to check if the server side of the General Diagnostics cluster is included
#define ZCL_USING_GENERAL_DIAGNOSTICS_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_GENERAL_DIAGNOSTICS_SERVER
#define EMBER_AF_PLUGIN_GENERAL_DIAGNOSTICS

// Use this macro to check if the server side of the Software Diagnostics cluster is included
#define ZCL_USING_SOFTWARE_DIAGNOSTICS_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_SOFTWARE_DIAGNOSTICS_SERVER
#define EMBER_AF_PLUGIN_SOFTWARE_DIAGNOSTICS

// Use this macro to check if the server side of the Thread Network Diagnostics cluster is included
#define ZCL_USING_THREAD_NETWORK_DIAGNOSTICS_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_THREAD_NETWORK_DIAGNOSTICS_SERVER
#define EMBER_AF_PLUGIN_THREAD_NETWORK_DIAGNOSTICS

// Use this macro to check if the server side of the WiFi Network Diagnostics cluster is included
#define ZCL_USING_WIFI_NETWORK_DIAGNOSTICS_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_WI_FI_NETWORK_DIAGNOSTICS_SERVER
#define EMBER_AF_PLUGIN_WI_FI_NETWORK_DIAGNOSTICS

// Use this macro to check if the server side of the Ethernet Network Diagnostics cluster is included
#define ZCL_USING_ETHERNET_NETWORK_DIAGNOSTICS_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_ETHERNET_NETWORK_DIAGNOSTICS_SERVER
#define EMBER_AF_PLUGIN_ETHERNET_NETWORK_DIAGNOSTICS

// Use this macro to check if the server side of the Switch cluster is included
#define ZCL_USING_SWITCH_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_SWITCH_SERVER
#define EMBER_AF_PLUGIN_SWITCH

// Use this macro to check if the server side of the Administrator Commissioning cluster is included
#define ZCL_USING_ADMINISTRATOR_COMMISSIONING_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_ADMINISTRATOR_COMMISSIONING_SERVER
#define EMBER_AF_PLUGIN_ADMINISTRATOR_COMMISSIONING

// Use this macro to check if the server side of the Operational Credentials cluster is included
#define ZCL_USING_OPERATIONAL_CREDENTIALS_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_OPERATIONAL_CREDENTIALS_SERVER
#define EMBER_AF_PLUGIN_OPERATIONAL_CREDENTIALS

// Use this macro to check if the server side of the Group Key Management cluster is included
#define ZCL_USING_GROUP_KEY_MANAGEMENT_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_GROUP_KEY_MANAGEMENT_SERVER
#define EMBER_AF_PLUGIN_GROUP_KEY_MANAGEMENT

// Use this macro to check if the server side of the Fixed Label cluster is included
#define ZCL_USING_FIXED_LABEL_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_FIXED_LABEL_SERVER
#define EMBER_AF_PLUGIN_FIXED_LABEL

// Use this macro to check if the server side of the User Label cluster is included
#define ZCL_USING_USER_LABEL_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_USER_LABEL_SERVER
#define EMBER_AF_PLUGIN_USER_LABEL

// Use this macro to check if the server side of the Color Control cluster is included
#define ZCL_USING_COLOR_CONTROL_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_COLOR_CONTROL_SERVER
#define EMBER_AF_PLUGIN_COLOR_CONTROL
// User options for server plugin Color Control
#define EMBER_AF_PLUGIN_COLOR_CONTROL_SERVER_XY
#define EMBER_AF_PLUGIN_COLOR_CONTROL_SERVER_TEMP
#define EMBER_AF_PLUGIN_COLOR_CONTROL_SERVER_HSV

// Use this macro to check if the server side of the Occupancy Sensing cluster is included
#define ZCL_USING_OCCUPANCY_SENSING_CLUSTER_SERVER
#define EMBER_AF_PLUGIN_OCCUPANCY_SENSING_SERVER
#define EMBER_AF_PLUGIN_OCCUPANCY_SENSING
