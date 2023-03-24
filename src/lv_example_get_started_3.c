#include "../lvgl.h"


#if LV_BUILD_EXAMPLES && LV_USE_SLIDER

static lv_obj_t * label, label1;


static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
//este segmento es lo que puede ocurrir mientras ocurre el evento slider o lo que es lo mismo no dejan de move la barra desplazadora
/*Refresh the text*/
    lv_label_set_text_fmt(label, "%"LV_PRId32, lv_slider_get_value(slider));
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -15);    /*Align top of the slider*/
     LV_LOG_USER("Barra de desplazamiento");
    //moviendo un servo motor con un slider
 


}

/**
 * Create a slider and write its value on a label.
 */
void lv_example_get_started_3(void)
{
    /*Create a slider in the center of the display*/
    lv_obj_t * slider = lv_slider_create(lv_scr_act());
    lv_slider_set_range(slider, 0 , 300);
    lv_obj_set_width(slider, 400);  
    lv_obj_set_height(slider,15);                        /*Set the width*/
    //lv_obj_center(slider);  
    //lv_obj_align(slider, LV_ALIGN_BOTTOM_MID, 0, 0);  /*esta es otra manera de posicionar un objeto creado*/
    lv_obj_set_pos(slider, 55, 240);   /*Aqui es donde le damos la posicion al*/
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);     /*Assign an event function*/

    /*Create a label above the slider*/
    label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "0");
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -15);    /*Align top of the slider*/



}

#endif

