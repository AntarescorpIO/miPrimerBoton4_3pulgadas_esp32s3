#include "../lvgl.h"
#include "Arduino.h"
#define led_1 13        //colocamos un led al terminal 13 de la tarjeta 7.0inch_ESP32-8048S070
#if LV_BUILD_EXAMPLES && LV_USE_BTN

 void tiempo_prendido_led_1(lv_timer_t * timer)
{
    digitalWrite(led_1, LOW);
      LV_LOG_USER("aver si no se repite");
      lv_timer_del(timer);
}

static void btn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        static uint8_t cnt = 0;
        cnt++;
        /*Get the first child of the button which is the label and change its text*/
        lv_obj_t * label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "abrieron el refrigerador: %d veces", cnt);
        LV_LOG_USER("ABRIERON EL REFRI");
        digitalWrite(led_1, HIGH);
        lv_timer_t * timer = lv_timer_create(tiempo_prendido_led_1,1000,NULL);
                                                    //las siguientes lineas son para hacer que el led que encendiste con este boton se apague 
                                                                                //despues de un tiempo que le vamos a dar en este timer
                                                        

    }
}

/**
 * Create a button with a label and react on click event.
 * crea un boton con la etiquera y reacciona al evento picale wey
 */

void lv_example_get_started_1(void)
{
    lv_obj_t * btn = lv_btn_create(lv_scr_act());     /*Add a button the current screen*/
    lv_obj_set_pos(btn,100, 100);                            /*le damos posicion*/
    lv_obj_set_size(btn, 300, 30);                          /*Set le damos tamaño*/
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);  /*le asigna una interrupcion al boton*/

    lv_obj_t * label = lv_label_create(btn);          /*Add a label to the button*/
    lv_label_set_text(label, "Puerta de refrigerador");   /*Se le coloca una primer etiquete o nombre*/
    lv_obj_center(label);
    pinMode(led_1, OUTPUT);    
}

#endif

