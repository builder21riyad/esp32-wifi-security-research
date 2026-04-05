/**
 * @file webserver.h
 * @author risinek (risinek@gmail.com)
 * @date 2021-04-05
 * @copyright Copyright (c) 2021
 * * @brief Provides interface to control and communicate with Webserver component
 */
#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "esp_event.h"

ESP_EVENT_DECLARE_BASE(WEBSERVER_EVENTS);
enum {
    WEBSERVER_EVENT_ATTACK_REQUEST,
    WEBSERVER_EVENT_ATTACK_RESET
};

/**
 * @brief Struct updated for 32-bit timeout and memory alignment
 */
typedef struct {
    uint8_t ap_record_id;   
    uint8_t type;           
    uint8_t method;         
    uint32_t timeout;       // CHANGED: uint8_t to uint32_t
} __attribute__((packed)) attack_request_t; // ADDED: packed attribute

void webserver_run();

#endif