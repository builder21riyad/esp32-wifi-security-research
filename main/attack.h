/**
 * @file attack.h
 * @author risinek (risinek@gmail.com)
 * @date 2021-04-02
 * @copyright Copyright (c) 2021
 *
 * @brief Provides interface to attack wrapper
 */

#ifndef ATTACK_H
#define ATTACK_H

#include "esp_wifi_types.h"

typedef enum {
    ATTACK_TYPE_PASSIVE,
    ATTACK_TYPE_HANDSHAKE,
    ATTACK_TYPE_PMKID,
    ATTACK_TYPE_DOS
} attack_type_t;

typedef enum {
    READY,      
    RUNNING,    
    FINISHED,   
    TIMEOUT     
} attack_state_t;

/**
 * @brief Attack config updated for 32-bit timeout
 */
typedef struct {
    uint8_t type;
    uint8_t method;
    uint32_t timeout;       // CHANGED: uint8_t to uint32_t
    const wifi_ap_record_t *ap_record;
} attack_config_t;

typedef struct {
    uint8_t state;  
    uint8_t type;   
    uint16_t content_size;
    char *content;
} attack_status_t;

const attack_status_t *attack_get_status();
void attack_update_status(attack_state_t state);
void attack_init();
char *attack_alloc_result_content(unsigned size);
void attack_append_status_content(uint8_t *buffer, unsigned size);

#endif