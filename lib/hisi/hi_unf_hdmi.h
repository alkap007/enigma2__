
/******************************************************************************

  Copyright (C), 2001-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_hdmi.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009-12-10
  Description   :
  History       :
  1.Date        : 2009-12-10
    Author      : sdk
    Modification: Created file

*******************************************************************************/

#ifndef __HI_UNF_HDMI_H__
#define __HI_UNF_HDMI_H__

/* add include here */
#include "hi_unf_common.h"
#include "hi_unf_sound.h"
#include "hi_unf_edid.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*************************** Structure Definition ****************************/
/** \addtogroup      HDMI */
/** @{ */  /** <!-- [HDMI] */

/**the max infoframe length*//**CNcomment:\D7\EE\B4\F3\D0\C5Ϣ֡\B3\A4\B6\C8 */
#define HI_UNF_HDMI_MAX_INFOFRAME_LEN   0X20

/**HDMI default value*//**CNcomment:HDMI ȱʡֵ */
#define HI_UNF_HDMI_DEFAULT_SETTING     0x00

/**HDMI interface ID *//**CNcomment:HDMI\BDӿ\DAID  */
typedef enum hiUNF_HDMI_ID_E
{
    HI_UNF_HDMI_ID_0         = 0,          /**<HDMI interface 0*/ /**<CNcomment:HDMI\BDӿ\DA0 */
    HI_UNF_HDMI_ID_BUTT
} HI_UNF_HDMI_ID_E;

/**HDMI event type*//**CNcomment: HDMI\CA¼\FE\C0\E0\D0\CD */
typedef enum hiUNF_HDMI_EVENT_TYPE_E
{
    HI_UNF_HDMI_EVENT_HOTPLUG = 0x10,       /**<HDMI HotPlug event type*//**<CNcomment:<HDMI\C8Ȳ\E5\B0\CE\CA¼\FE */
    HI_UNF_HDMI_EVENT_NO_PLUG,              /**<HDMI unplug event type*//**<CNcomment:HDMI Cableû\D3\D0\C1\AC\BD\D3 \CA¼\FE */
    HI_UNF_HDMI_EVENT_EDID_FAIL,            /**<HDMI read edid fail event type*//**<CNcomment:HDMI EDID\B6\C1ȡʧ\B0\DC\CA¼\FE */
    HI_UNF_HDMI_EVENT_HDCP_FAIL,            /**<HDCP authentication fail event type *//**<CNcomment:HDCP\D1\E9֤ʧ\B0\DC\CA¼\FE */
    HI_UNF_HDMI_EVENT_HDCP_SUCCESS,         /**<HDCP authentication succeed event type*//**<CNcomment:HDCP\D1\E9֤\B3ɹ\A6 */
    HI_UNF_HDMI_EVENT_RSEN_CONNECT,         /**<TMDS link is connected*//**<CNcomment:TMDS\C1\B4\BDӳɹ\A6 */
    HI_UNF_HDMI_EVENT_RSEN_DISCONNECT,      /**<TMDS link is disconnected*//**<CNcomment:TMDSδ\C1\B4\BD\D3 */
    HI_UNF_HDMI_EVENT_HDCP_USERSETTING,     /**<HDMI Reset *//**<CNcomment:HDCP \B8\B4λ*/
    HI_UNF_HDMI_EVENT_BUTT
}HI_UNF_HDMI_EVENT_TYPE_E;

/*Video color space mode*//**CNcomment:\CA\D3Ƶ\D1\D5ɫ\BFռ\E4\C0\E0\D0\CD*/
typedef enum hiUNF_HDMI_VIDEO_MODE
{
    HI_UNF_HDMI_VIDEO_MODE_RGB444,          /**<RGB444 output mode*//**<CNcomment:RGB444\CA\E4\B3\F6ģʽ */
    HI_UNF_HDMI_VIDEO_MODE_YCBCR422,        /**<YCBCR422 output mode*//**<CNcomment:YCBCR422\CA\E4\B3\F6ģʽ */
    HI_UNF_HDMI_VIDEO_MODE_YCBCR444,        /**<YCBCR444 output mode*//**<CNcomment:YCBCR444\CA\E4\B3\F6ģʽ */
    HI_UNF_HDMI_VIDEO_MODE_YCBCR420,        /**<YCBCR420 output mode*//**<CNcomment:YCBCR420\CA\E4\B3\F6ģʽ */
    HI_UNF_HDMI_VIDEO_MODE_BUTT
}HI_UNF_HDMI_VIDEO_MODE_E;

/*HDMI Output Aspect Ratio*//**CNcomment:HDMI\CA\E4\B3\F6\BF\ED\B8߱\C8*/
typedef enum hiUNF_HDMI_ASPECT_RATIO_E
{
    HI_UNF_HDMI_ASPECT_RATIO_NO_DATA,        /**<Aspect Ratio unknown *//**<CNcomment:δ֪\BF\ED\B8߱\C8 */
    HI_UNF_HDMI_ASPECT_RATIO_4TO3,           /**<Aspect Ratio 4:3  *//**<CNcomment:\BF\ED\B8߱\C84:3*/
    HI_UNF_HDMI_ASPECT_RATIO_16TO9,          /**<Aspect Ratio 16:9 *//**<CNcomment:\BF\ED\B8߱\C816:9 */
    HI_UNF_HDMI_ASPECT_RATIO_64TO27,
    HI_UNF_HDMI_ASPECT_RATIO_256TO135,
    HI_UNF_HDMI_ASPECT_RATIO_FUTURE,
    HI_UNF_HDMI_ASPECT_RATIO_BUTT
}HI_UNF_HDMI_ASPECT_RATIO_E;


/**HDMI Deep color mode*//**CNcomment: HDMI \C9\EEɫģʽ */
typedef enum hiUNF_HDMI_DEEP_COLOR_E
{
    HI_UNF_HDMI_DEEP_COLOR_24BIT = 0x00,    /**<HDMI Deep color 24bit mode*//**<CNcomment:HDMI 24bit \C9\EEɫģʽ  */
    HI_UNF_HDMI_DEEP_COLOR_30BIT,           /**<HDMI Deep color 30bit mode*//**<CNcomment:HDMI 30bit \C9\EEɫģʽ  */
    HI_UNF_HDMI_DEEP_COLOR_36BIT,           /**<HDMI Deep color 36bit mode*//**<CNcomment:HDMI 36bit \C9\EEɫģʽ  */
    HI_UNF_HDMI_DEEP_COLOR_OFF   = 0xff,
    HI_UNF_HDMI_DEEP_COLOR_BUTT
}HI_UNF_HDMI_DEEP_COLOR_E;

/**HDMI AVI infoframe BarInfo enum*//**CNcomment: HDMI AVI\D0\C5Ϣ֡ BarInfo ö\BE\D9 */
typedef enum hiUNF_HDMI_BARINFO_E
{
   HDMI_BAR_INFO_NOT_VALID,                 /**<Bar Data not valid *//**<CNcomment:\CE\DEЧBar\CA\FD\BE\DD  */
   HDMI_BAR_INFO_V,                         /**<Vertical bar data valid *//**<CNcomment:\B4\B9ֱBar\CA\FD\BE\DD\D3\D0Ч  */
   HDMI_BAR_INFO_H,                         /**<Horizental bar data valid *//**<CNcomment:ˮƽbar\CA\FD\BE\DD\D3\D0Ч  */
   HDMI_BAR_INFO_VH                         /**<Horizental and Vertical bar data valid *//**<CNcomment:ˮƽ\B4\B9ֱBar\CA\FD\BE\DDͬʱ\D3\D0Ч */
}HI_UNF_HDMI_BARINFO_E;

/**HDMI AVI infofram ScanInfo enum*//**CNcomment: HDMI AVI\D0\C5Ϣ֡ ScanInfo ö\BE\D9 */
typedef enum hiUNF_HDMI_SCANINFO_E
{
    HDMI_SCAN_INFO_NO_DATA      = 0,        /**< No Scan information*//**<CNcomment:\CE\DEɨ\C3\E8\D0\C5Ϣ  */
    HDMI_SCAN_INFO_OVERSCANNED  = 1,        /**< Scan information, Overscanned (for television) *//**<CNcomment:ɨ\C3\E8\D0\C5Ϣ:ȫ\BB\AD\C3\E6ɨ\C3\E8  */
    HDMI_SCAN_INFO_UNDERSCANNED = 2,        /**< Scan information, Underscanned (for computer) *//**<CNcomment:ɨ\C3\E8\D0\C5Ϣ: \B7\C7ȫ\BB\AD\C3\E6ɨ\C3\E8  */
    HDMI_SCAN_INFO_FUTURE
}HI_UNF_HDMI_SCANINFO_E;

/**HDMI AVI InfoFrame picture scale enum*//**CNcomment: HDMI AVI\D0\C5Ϣ֡ Picture scale ö\BE\D9 */
typedef enum hiUNF_HDMI_PICTURE_SCALING_E
{
    HDMI_PICTURE_NON_UNIFORM_SCALING,       /**< No Known, non-uniform picture scaling  *//**<CNcomment:ͳһͼ\CF\F1\D7\F8\B1\EA  */
    HDMI_PICTURE_SCALING_H,                 /**< Picture has been scaled horizentally *//**<CNcomment:ͼ\CF\F1ˮƽ\D7\F8\B1껯  */
    HDMI_PICTURE_SCALING_V,                 /**< Picture has been scaled Vertically *//**<CNcomment:ͼ\CF\F1\B4\B9ֱ\D7\F8\B1껯  */
    HDMI_PICTURE_SCALING_HV                 /**< Picture has been scaled Horizentally and Vertically   *//**<CNcomment:ͼ\CF\F1ˮƽ\B4\B9ֱ\D7\F8\B1껯  */
} HI_UNF_HDMI_PICTURE_SCALING_E;

/**HDMI AVI InfoFrame colorimetry enum*//**CNcomment: HDMI AVI\D0\C5Ϣ֡ ɫ\B6ȿռ\E4 ö\BE\D9 */
typedef enum hiUNF_HDMI_COLORSPACE_E
{
    HDMI_COLORIMETRY_NO_DATA,               /**<Colorimetry No Data option*//**<CNcomment:Colorimetry No Dataѡ\CF\EE */
    HDMI_COLORIMETRY_ITU601,                /**<Colorimetry ITU601 option*//**<CNcomment:Colorimetry ITU601ɫ\B6ȿռ\E4ѡ\CF\EE */
    HDMI_COLORIMETRY_ITU709,                /**<Colorimetry ITU709 option*//**<CNcomment:Colorimetry ITU709ɫ\B6ȿռ\E4ѡ\CF\EE */
    HDMI_COLORIMETRY_EXTENDED,              /**<Colorimetry extended option*//**<CNcomment:Colorimetry \C0\A9չѡ\CF\EE */
    HDMI_COLORIMETRY_XVYCC_601,             /**<Colorimetry xvYCC601 extened option*//**<CNcomment:Colorimetry xvYCC601\C0\A9չѡ\CF\EE */
    HDMI_COLORIMETRY_XVYCC_709,             /**<Colorimetry xvYCC709 extened option*//**<CNcomment:Colorimetry xvYCC709\C0\A9չѡ\CF\EE */
    HDMI_COLORIMETRY_S_YCC_601,             /**<Colorimetry S YCC 601 extened option*//**<CNcomment:Colorimetry S YCC 601\C0\A9չѡ\CF\EE */
    HDMI_COLORIMETRY_ADOBE_YCC_601,         /**<Colorimetry ADOBE YCC 601 extened option*//**<CNcomment:Colorimetry ADOBE YCC 601\C0\A9չѡ\CF\EE */
    HDMI_COLORIMETRY_ADOBE_RGB,             /**<Colorimetry ADOBE RGB extened option*//**<CNcomment:Colorimetry ADOBE RGB\C0\A9չѡ\CF\EE */
    HDMI_COLORIMETRY_2020_CONST_LUMINOUS,    /**<Colorimetry ITU2020 extened option*//**<CNcomment:Colorimetry ITU2020\C0\A9չѡ\CF\EE:BT2020cYCC */
    HDMI_COLORIMETRY_2020_NON_CONST_LUMINOUS,/**<Colorimetry ITU2020 extened option*//**<CNcomment:Colorimetry ITU2020\C0\A9չѡ\CF\EE:BT2020RGB\BB\F2BT2020YCC*/
} HI_UNF_HDMI_COLORSPACE_E;

/**HDMI AVI InfoFrame RGB range enum*//**CNcomment: HDMI AVI\D0\C5Ϣ֡ RGBɫ\B6ȷ\B6Χ ö\BE\D9 */
typedef enum hiUNF_HDMI_RGB_QUAN_RAGE_E
{
    HDMI_RGB_QUANTIZATION_DEFAULT_RANGE,    /**< Defaulr range, it depends on the video format *//**<CNcomment:Ĭ\C8\CFɫ\B6ȷ\B6Χ\A3\AC\D2\C0\C0\B5\D3\DA\CA\D3Ƶ\D6\C6ʽ */
    HDMI_RGB_QUANTIZATION_LIMITED_RANGE,    /**< Limited quantization range of 220 levels when receiving a CE video format*//**<CNcomment:\CA\DC\CF\DEɫ\B6ȷ\B6Χ16-234 */
    HDMI_RGB_QUANTIZATION_FULL_RANGE        /**< Full quantization range of 256 levels when receiving an IT video format*//**<CNcomment:ȫɫ\B6ȷ\B6Χ 0-255 */
} HI_UNF_HDMI_RGB_QUAN_RAGE_E;

/**HDMI AVI InfoFrame YCC quantization range enum *//**CNcomment:HDMI AVI\D0\C5Ϣ֡ YCCɫ\B6ȷ\B6Χ ö\BE\D9 */
typedef enum hiUNF_HDMI_YCC_QUAN_RAGE_E
{
    HDMI_YCC_QUANTIZATION_LIMITED_RANGE,    /**< Limited quantization range of 220 levels when receiving a CE video format*//**<CNcomment:\CA\DC\CF\DEɫ\B6ȷ\B6Χ16-234 */
    HDMI_YCC_QUANTIZATION_FULL_RANGE        /**< Full quantization range of 256 levels when receiving an IT video format*//**<CNcomment:ȫɫ\B6ȷ\B6Χ 0-255 */
}HI_UNF_HDMI_YCC_QUAN_RAGE_E;

/**HDMI AVI InfoFrame AVI video content type enum*//**CNcomment:HDMI AVI\D0\C5Ϣ֡ AVI\CA\D3Ƶ\C4\DA\C8ݵ\C4\C0\E0\D0\CD ö\BE\D9 */
typedef enum hiUNF_HDMI_CONTENT_TYPE_E
{
    HDMI_CONTNET_GRAPHIC,                   /**< Graphics type*//**<CNcomment:ͼ\CF\F1 */
    HDMI_CONTNET_PHOTO,                     /**< Photo type*//**<CNcomment:\D5\D5Ƭ */
    HDMI_CONTNET_CINEMA,                    /**< Cinema type*//**<CNcomment:\B5\E7ӰԺ */
    HDMI_CONTNET_GAME                       /**< Game type*//**<CNcomment:\D3\CEϷ */
}HI_UNF_HDMI_CONTENT_TYPE_E;

/**HDMI Priority judgments strategy enum*//**CNcomment:HDMI \D3\C5\CF\C8\C5жϲ\DF\C2\D4 ö\BE\D9*/
typedef enum hiUNF_HDMI_DEFAULT_ACTION_E
{
    HI_UNF_HDMI_DEFAULT_ACTION_NULL,   /**<Default action null*//**<CNcomment:\CE\DEĬ\C8\CF\D3\C5\CFȲ\DF\C2\D4 */
    HI_UNF_HDMI_DEFAULT_ACTION_HDMI,   /**<Default action HDMI*//**<CNcomment:\D3\C5\CF\C8\C5ж\CFHDMI */
    HI_UNF_HDMI_DEFAULT_ACTION_DVI,    /**<Default action DVI*//**<CNcomment:\D3\C5\CF\C8\C5ж\CFDVI */
    HI_UNF_HDMI_DEFAULT_ACTION_BUTT
}HI_UNF_HDMI_DEFAULT_ACTION_E;


/**The hotplug callback function interface */
/**CNcomment: \BDӿ\DA\C8Ȳ\E5\B0λص\F7\BA\AF\CA\FD */
typedef void (*HI_UNF_HDMI_CALLBACK)(HI_UNF_HDMI_EVENT_TYPE_E event, HI_VOID *pPrivateData);

/**HDMI Callback Struct*/
/**CNcomment: HDMI\BBص\F7\BDṹ */
typedef struct hiUNF_HDMI_CALLBACK_FUNC_S
{
    HI_UNF_HDMI_CALLBACK pfnHdmiEventCallback;  /**<callback function pointer*//**<CNcomment:\BBص\F7\BA\AF\CA\FDָ\D5\EB*/
    HI_VOID             *pPrivateData;         /**<callback funtion param*//**<CNcomment:\BBص\F7\BA\AF\CA\FD\B2\CE\CA\FD*/
 }HI_UNF_HDMI_CALLBACK_FUNC_S;

/**HDMI Open Param*/
/**CNcomment: HDMI\B4򿪲\CE\CA\FD */
typedef struct hiUNF_HDMI_OPEN_PARA_S
{
    HI_UNF_HDMI_DEFAULT_ACTION_E enDefaultMode;/**<HDMI Priority judgments strategy enum*//**<CNcomment:HDMI \D3\C5\CF\C8\C5жϲ\DF\C2\D4 ö\BE\D9*/
}HI_UNF_HDMI_OPEN_PARA_S;

/**Current HDCP version enum*/
/**CNcomment:\B5\B1ǰHDCP\B0汾 ö\BE\D9*/
typedef enum hiUNF_HDMI_HDCP_VERSION_E
{
    HI_UNF_HDMI_HDCP_VERSION_NONE,      /**<HDCP version, none HDCP*//**<CNcomment:\CE\DEHDCP */
    HI_UNF_HDMI_HDCP_VERSION_HDCP14,    /**<HDCP version, HDCP1.4*//**<CNcomment:HDCP1.4 */
    HI_UNF_HDMI_HDCP_VERSION_HDCP22,    /**<HDCP version, HDCP2.2*//**<CNcomment:HDCP2.2 */
    HI_UNF_HDMI_HDCP_VERSION_BUTT
}HI_UNF_HDMI_HDCP_VERSION_E;

/**HDMI status*/
/**CNcomment: HDMI״̬ */
typedef struct hiUNF_HDMI_STATUS_S
{
    HI_BOOL                 bConnected;             /**<The Device is connected or disconnected *//**<CNcomment:\C9豸\CAǷ\F1\C1\AC\BD\D3 */
    HI_BOOL                 bSinkPowerOn;           /**<The sink is PowerOn or not*//**<CNcomment:Sink\C9豸\CAǷ\F1\C9ϵ\E7 */
    HI_BOOL                 bAuthed;                /**<HDCP Authentication *//**<CNcomment:HDCP \CAǷ\F1\CE\D5\CA\D6\CD\EA\B3\C9 */
    HI_U8                   u8Bksv[5];              /**<Bksv of sink 40bits*//**<CNcomment:\BD\D3\CAն˵\C4Bksv */
    HI_UNF_HDMI_HDCP_VERSION_E enHDCPVersion;       /**<Current HDCP version*//**<CNcomment:\B5\B1ǰHDCP\B0汾 */
}HI_UNF_HDMI_STATUS_S;

/**Current HDCP mode enum*/
/**CNcomment:HDCPģʽ ö\BE\D9*/
typedef enum hiUNF_HDMI_HDCP_MODE_E
{
    HI_UNF_HDMI_HDCP_MODE_AUTO,         /**< HDCP auto mode,priority is 2.2 then 1.4 to set HDCP according to sink's HDCP-capability *//**<CNcomment:HDCP\D7Զ\AFģʽ\A3\ACHDMI\C7\FD\B6\AF\B8\F9\BE\DDSink\B6\CB\C4\DC\C1\A6\D7Զ\AFѡ\D4\F1HDCP\C8\CF֤\B0汾\A3\AC2.2\D3\C5\CF\C8\D3\DA1.4 */
    HI_UNF_HDMI_HDCP_MODE_1_4,          /**< forec to HDCP1.4 disregard sink's HDCP-capability.It may be fail due to sink not support. *//**<CNcomment:ǿ\D6\C6\C9\E8\D6\C3HDCP1.4\B0汾\A3\AC\B2\BB\B2ο\BCsink\C4\DC\C1\A6\A1\A3δ\B2ο\BCsink\C4\DC\C1\A6\B6\F8ǿ\D6\C6ʹ\C4ܿ\C9\C4ܵ\BC\D6\C2\C8\CF֤ʧ\B0ܡ\A3 */
    HI_UNF_HDMI_HDCP_MODE_2_2,          /**< forec to HDCP2.2 disregard sink's HDCP-capability.It may be fail due to sink not support. *//**<CNcomment:ǿ\D6\C6\C9\E8\D6\C3HDCP2.2\B0汾\A3\AC\B2\BB\B2ο\BCsink\C4\DC\C1\A6\A1\A3δ\B2ο\BCsink\C4\DC\C1\A6\B6\F8ǿ\D6\C6ʹ\C4ܿ\C9\C4ܵ\BC\D6\C2\C8\CF֤ʧ\B0ܡ\A3 */
    HI_UNF_HDMI_HDCP_BUTT
}HI_UNF_HDMI_HDCP_MODE_E;

/**the config parameter of HDMI interface*/
/**CNcomment:HDMI \BDӿڲ\CE\CA\FD\C5\E4\D6\C3 */
typedef struct hiUNF_HDMI_ATTR_S
{
    HI_BOOL                 bEnableHdmi;         /**<force to HDMI or DVI,the value must set before HI_UNF_HDMI_Start or behind HI_UNF_HDMI_Stop*//**<CNcomment:\CAǷ\F1ǿ\D6\C6HDMI,\B7\F1\D4\F2ΪDVI.\B8\C3ֵ\B1\D8\D0\EB\D4\DA HI_UNF_HDMI_Start֮ǰ\BB\F2\D5\DFHI_UNF_HDMI_Stop֮\BA\F3\C9\E8\D6\C3  */

    HI_BOOL                 bEnableVideo;        /**<parameter must set HI_TRUE,or the HDMI diver will force to set HI_TRUE*//**<CNcomment:\B1\D8\D0\EB\CA\C7HI_TRUE, \C8\E7\B9\FB\CA\C7HI_FALSE:HDMI\C7\FD\B6\AF\BB\E1ǿ\D6\C6\C9\E8\D6\C3ΪHI_TRUE */

    HI_UNF_HDMI_VIDEO_MODE_E enVidOutMode;       /**<HDMI output vedio mode VIDEO_MODE_YCBCR,VIDEO_MODE_YCBCR444,VIDEO_MODE_YCBCR422,VIDEO_MODE_RGB444 *//**<CNcomment:HDMI\CA\E4\B3\F6\CA\D3Ƶģʽ\A3\ACVIDEO_MODE_YCBCR444\A3\ACVIDEO_MODE_YCBCR422\A3\ACVIDEO_MODE_RGB444 */
    HI_UNF_HDMI_DEEP_COLOR_E enDeepColorMode;    /**<Deep Color output mode,defualt: HI_UNF_HDMI_DEEP_COLOR_24BIT *//**<CNcomment:DeepColor\CA\E4\B3\F6ģʽ, Ĭ\C8\CFΪHI_UNF_HDMI_DEEP_COLOR_24BIT */
    HI_BOOL                 bxvYCCMode;          /**<the xvYCC output mode,default:HI_FALSE*//**<CNcomment:< xvYCC\CA\E4\B3\F6ģʽ\A3\ACĬ\C8\CFΪHI_FALSE */

    HI_BOOL                 bEnableAudio;        /**<Enable flag of Audio*//**CNcomment:\CAǷ\F1Enable\D2\F4Ƶ */

    HI_BOOL                 bEnableAviInfoFrame; /**<Enable flag of AVI InfoFrame,suggestion:enable *//**<CNcomment:\CAǷ\F1ʹ\C4\DC AVI InfoFrame\A3\AC\BD\A8\D2\E9ʹ\C4\DC */
    HI_BOOL                 bEnableAudInfoFrame; /**<Enable flag of Audio InfoFrame,suggestion:enable*//**<CNcomment:\CAǷ\F1ʹ\C4\DC AUDIO InfoFrame\A3\AC\BD\A8\D2\E9ʹ\C4\DC */
    HI_BOOL                 bEnableSpdInfoFrame; /**<Enable flag of SPD info frame,suggestion:disable*//**<CNcomment:\CAǷ\F1ʹ\C4\DC SPD InfoFrame\A3\AC \BD\A8\D2\E9\B9ر\D5 */
    HI_BOOL                 bEnableMpegInfoFrame;/**<Enable flag of MPEG info frame,suggestion:disable*//**<CNcomment:\CAǷ\F1ʹ\C4\DC MPEG InfoFrame\A3\AC \BD\A8\D2\E9\B9ر\D5 */

    HI_BOOL                 bHDCPEnable;         /**<0:HDCP disable mode,1:eable HDCP mode.see HI_UNF_HDMI_HdcpEanble*//**<CNcomment:< 0:HDCP\B2\BB\BC\A4\BB1:HDCPģʽ\B4򿪡\A3\BC\FBHI_UNF_HDMI_HdcpEanble */

    HI_BOOL                 bEnableVidModeAdapt; /**<Enable flag of vedio mode & DVI adapting case of user setting incorrect,default:HI_TRUE.When user have no any adapting strategy,suggestion HI_TRUE*//**<CNcomment:\B5\B1\D3û\A7\C9\E8\D6õ\C4\CA\E4\B3\F6\D1\D5ɫ\BFռ\E4\D3\EBDVI \B4\ED\CE\F3ʱ\CAǷ\F1ʹ\C4\DC \D7Զ\AFУ\D5\FD\A3\AC\B2\BBʹ\C4\DC\D4\F2\D3û\A7\C9\E8\D6ô\ED\CE\F3ʱֱ\BDӷ\B5\BB\D8ʧ\B0ܣ\ACĬ\C8\CFʹ\C4\DC \A1\A3\BD\A8\D2鵱\D3û\A7\D3\D0\D7\D4\CA\CAӦ\B2\DF\C2\D4ʱ\B9رգ\AC\B7\F1\D4\F2ʹ\C4\DC*/
    HI_BOOL                 bEnableDeepClrAdapt; /**<Enable flag of deep color mode adapting case of user setting incorrect,default: HI_FALSE.When user have no any adapting strategy,suggestion HI_TRUE*//**<CNcomment:\B5\B1\D3û\A7\C9\E8\D6õ\C4\CA\E4\B3\F6ɫ\C9\EE(λ\BF\ED)\B4\ED\CE\F3ʱ\CAǷ\F1ʹ\C4\DC \D7Զ\AFУ\D5\FD\A3\AC\B2\BBʹ\C4\DC\D4\F2\D3û\A7\C9\E8\D6ô\ED\CE\F3ʱֱ\BDӷ\B5\BB\D8ʧ\B0ܣ\ACĬ\C8\CFʹ\C4ܡ\A3\BD\A8\D2鵱\D3û\A7\D3\D0\D7\D4\CA\CAӦ\B2\DF\C2\D4ʱ\B9رգ\AC\B7\F1\D4\F2ʹ\C4\DC*/
    HI_BOOL                 bAuthMode;           /**<Enable flag of authentication, suggestion:disable *//**<CNcomment:\CAǷ\F1ʹ\C4\DC\C8\CF֤ģʽ\A3\AC\BD\A8\D2\E9Ĭ\C8ϲ\BB\CA\C7\C4\DC */
    HI_UNF_HDMI_HDCP_MODE_E enHDCPMode;          /**<HDCP mode:HI_UNF_HDMI_HDCP_MODE_AUTO, HI_UNF_HDMI_HDCP_MODE_1_4,HI_UNF_HDMI_HDCP_MODE_2_2,see HI_UNF_HDMI_HdcpEanble*//**<CNcomment:< HDCP\B5ȼ\B6\A3\ACHI_UNF_HDMI_HDCP_MODE_AUTO(\B8\F9\BE\DD\C4\DC\C1\A6\D7Զ\AFѡ\D4\F1)\A3\ACHI_UNF_HDMI_HDCP_MODE_1_4,HI_UNF_HDMI_HDCP_MODE_2_2. \BC\FBHI_UNF_HDMI_HdcpEanble */
}HI_UNF_HDMI_ATTR_S;

/**HDMI infoFrame type definition*/
/**CNcomment: HDMI \D0\C5Ϣ֡\C0\E0\D0Ͷ\A8\D2\E5 */
typedef enum tagHI_UNF_HDMI_INFOFRAME_TYPE_E
{
    HI_INFOFRAME_TYPE_AVI,          /**<HDMI AVI InfoFrame type defintion*//**<CNcomment:HDMI AVI InfoFrame \C0\E0\D0Ͷ\A8\D2\E5 */
    HI_INFOFRAME_TYPE_SPD,          /**<HDMI SPD InfoFrame type defintion*//**<CNcomment:HDMI SPD InfoFrame \C0\E0\D0Ͷ\A8\D2\E5 */
    HI_INFOFRAME_TYPE_AUDIO,        /**<HDMI AUDIO InfoFrame type defintion*//**<CNcomment:HDMI AUDIO InfoFrame \C0\E0\D0Ͷ\A8\D2\E5 */
    HI_INFOFRAME_TYPE_MPEG,         /**<HDMI MPEG InfoFrame type defintion*//**<CNcomment:HDMI MPEG InfoFrame \C0\E0\D0Ͷ\A8\D2\E5 */
    HI_INFOFRAME_TYPE_VENDORSPEC,   /**<HDMI Specific InfoFrame type defintion*//**<CNcomment:HDMI Vendor Specific InfoFrame \C0\E0\D0Ͷ\A8\D2\E5 */
    HI_INFOFRAME_TYPE_BUTT
}HI_UNF_HDMI_INFOFRAME_TYPE_E;

/**HDMI AVI InfoFrame parameter struct,please reference EIA-CEA-861-D*/
/**CNcomment: HDMI AVI \D0\C5Ϣ֡\B2\CE\CA\FD\BDṹ, \C7\EB\B2ο\BCEIA-CEA-861-D */
typedef struct hiUNF_HDMI_AVI_INFOFRAME_VER2_S
{
    HI_UNF_ENC_FMT_E               enTimingMode;            /**<AVI video timing format*//**<CNcomment:AVI\CA\D3Ƶtiming\B8\F1ʽ */
    HI_UNF_HDMI_VIDEO_MODE_E       enOutputType;            /**<AVI video output color space*//**<CNcomment:AVI\CA\D3Ƶ\CA\E4\B3\F6\D1\D5ɫ\B8\F1ʽ */
    HI_BOOL                        bActive_Infor_Present;   /**<AVI video Active_Infor_Present flag*//**<CNcomment:AVI\CA\D3ƵActive_Infor_Present\B1\EA־λ */
    HI_UNF_HDMI_BARINFO_E          enBarInfo;               /**<AVI video BarInfo type*//**<CNcomment:AVI\CA\D3ƵBarInfo\C0\E0\D0\CD */
    HI_UNF_HDMI_SCANINFO_E         enScanInfo;              /**<AVI video ScanInfo type*//**<CNcomment:AVI\CA\D3ƵScanInfo\C0\E0\D0\CD */
    HI_UNF_HDMI_COLORSPACE_E       enColorimetry;           /**<AVI video Colorimetry type*//**<CNcomment:AVI\CA\D3ƵColorimetry\C0\E0\D0\CD */
    HI_UNF_HDMI_ASPECT_RATIO_E     enAspectRatio;           /**<AVI video AspectRatio type*//**<CNcomment:AVI\CA\D3Ƶ\BF\ED\B8߱ȸ\F1ʽ */
    HI_UNF_HDMI_ASPECT_RATIO_E     enActiveAspectRatio;     /**<AVI video Active AspectRatio type*//**<CNcomment:AVI\CA\D3Ƶ\D3\D0Ч\BF\ED\B8߱ȸ\F1ʽ */
    HI_UNF_HDMI_PICTURE_SCALING_E  enPictureScaling;        /**<AVI video picture scaling type*//**<CNcomment:AVI\CA\D3Ƶscaling\B8\F1ʽ */
    HI_UNF_HDMI_RGB_QUAN_RAGE_E    enRGBQuantization;       /**<AVI video RGB Quantization*//**<CNcomment:AVI\CA\D3ƵRGBɫ\B6ȷ\B6Χ */
    HI_BOOL                        bIsITContent;            /**<AVI video ITContent flag*//**<CNcomment:AVI\CA\D3ƵITcontent */
    HI_U32                         u32PixelRepetition;      /**<AVI video Pixel Repetition flag*//**<CNcomment:AVI\CA\D3Ƶ\CF\F1\CB\D8\D6ش\AB\B1\EA־λ */

    HI_UNF_HDMI_CONTENT_TYPE_E     enContentType;           /**<AVI video content type*//**<CNcomment:AVI\CA\D3Ƶ\C4\DA\C8ݵ\C4\C0\E0\D0\CD */
    HI_UNF_HDMI_YCC_QUAN_RAGE_E    enYCCQuantization;       /**<AVI video YCC Quantization*//**CNcomment:*< AVI\CA\D3ƵYCCɫ\B6ȷ\B6Χ */

    HI_U32                         u32LineNEndofTopBar;     /**<AVI video EndofTopBar coordinate,defualt:0 *//**<CNcomment:AVI\CA\D3ƵEndofTopBar\D7\F8\B1꣬ȱʡΪ0 */
    HI_U32                         u32LineNStartofBotBar;   /**<AVI video StartofBotBar coordinate,defualt:0*//**<CNcomment:AVI\CA\D3ƵStartofBotBar\D7\F8\B1꣬ȱʡΪ0 */
    HI_U32                         u32PixelNEndofLeftBar;   /**<AVI video EndofLeft coordinate,defualt:0*//**<CNcomment:AVI\CA\D3ƵEndofLeft\D7\F8\B1꣬ȱʡΪ0 */
    HI_U32                         u32PixelNStartofRightBar;/**<AVI video StartofRightBar coordinate,defualt:0*//**<CNcomment:AVI\CA\D3ƵStartofRightBar\D7\F8\B1꣬ȱʡΪ0 */
}HI_UNF_HDMI_AVI_INFOFRAME_VER2_S;

/**HDMI AUDIO InfoFrame parameter struct ,please reference EIA-CEA-861-D*/
/**CNcomment: HDMI \D2\F4Ƶ\D0\C5Ϣ֡\B2\CE\CA\FD\BDṹ, \C7\EB\B2ο\BCEIA-CEA-861-D */
typedef struct hiUNF_HDMI_AUD_INFOFRAME_VER1_S
{
    HI_U32                            u32ChannelCount;          /**<audio frequency channel count*//**<CNcomment:\D2\F4Ƶ \C9\F9\B5\C0\CA\FD */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_E   enCodingType;             /**<audio frequency coding type,default 0;Refer to Stream Header*//**<CNcomment:\D2\F4Ƶ \B1\E0\C2\EB\C0\E0\D0ͣ\ACȱʡΪ0\A3\BARefer to Stream Header */
    HI_U32                            u32SampleSize;            /**<audio frequency sample size,default 0,Refer to Stream Header*//**<CNcomment:\D2\F4Ƶ \B2\C9\D1\F9\B4\F3С\A3\ACȱʡΪ0\A3\BARefer to Stream Header */
    HI_U32                            u32SamplingFrequency;     /**<audio frequency sampling frequency ,default 0,Refer to Stream Header*//**<CNcomment:\D2\F4Ƶ \B2\C9\D1\F9Ƶ\C2ʣ\ACȱʡΪ0\A3\BARefer to Stream Header */
    HI_U32                            u32ChannelAlloc;          /**<audio frequency channel allocable ,default 0,Refer to Stream Header*//**<CNcomment:\D2\F4Ƶ \C9\F9\B5\C0\B7\D6\C5䣬ȱʡΪ0\A3\BARefer to Stream Header */
    HI_U32                            u32LevelShift;            /**<audio frequency Levelshift ,default 0,Refer to Stream Header*//**<CNcomment:\D2\F4Ƶ Levelshift\A3\ACȱʡΪ0\A3\BARefer to Stream Header */
    HI_BOOL                           u32DownmixInhibit;        /**<audio frequency DownmixInhibit ,default 0,Refer to Stream Header*//**<CNcomment:\D2\F4Ƶ DownmixInhibit\A3\ACȱʡΪ0\A3\BARefer to Stream Header */
}HI_UNF_HDMI_AUD_INFOFRAME_VER1_S;

/**HDMI SPD InfoFrame parameter struct,please reference EIA-CEA-861-D*/
/**CNcomment: HDMI SPD\D0\C5Ϣ֡\B2\CE\CA\FD\BDṹ , \C7\EB\B2ο\BCEIA-CEA-861-D */
typedef struct hiUNF_HDMI_SPD_INFOFRAME_S
{
    HI_U8                          u8VendorName[8];          /**<vendor name*//**<CNcomment:\C2\F4\B7\BD\C3\FB\B3\C6 */
    HI_U8                          u8ProductDescription[16]; /**<product Description*//**<CNcomment:\B2\FAƷ\C3\E8\CA\F6\B7\FB */
    HI_U8                          u8SrcDevInfo;             /**<Source Device Information  *//**<CNcomment:Դ\C9豸\D0\C5Ϣ */
}HI_UNF_HDMI_SPD_INFOFRAME_S;

/**HDMI Source HDMI MPEG InfoFrame parameter struct,please reference EIA-CEA-861-D*/
/**CNcomment: HDMI MPEG\D0\C5Ϣ֡\B2\CE\CA\FD\BDṹ , \C7\EB\B2ο\BCEIA-CEA-861-D */
typedef struct hiUNF_HDMI_MPEGSOURCE_INFOFRAME_S
{
    HI_U32                         u32MPEGBitRate;           /**<MPEG bit Rate*//**<CNcomment:MPEGλ\C2\CA */
    HI_BOOL                        bIsFieldRepeated;         /**<FieldRepeater flag*//**<CNcomment:FieldRepeater\B1\EA־λ */
}HI_UNF_HDMI_MPEGSOURCE_INFOFRAME_S;

/**HDMI Vendor Specific InfoFrame parameter struct,please reference EIA-CEA-861-D*/
/**CNcomment: HDMI VSIF\D0\C5Ϣ֡ \B2\CE\CA\FD\BDṹ , \C7\EB\B2ο\BCEIA-CEA-861-D */
typedef struct hiUNF_HDMI_VENDORSPEC_INFOFRAME_S
{
    HI_U32                         u32RegistrationId;       /**<Registration Id*//**<CNcomment:ע\B2\E1ID\BA\C5 */
}HI_UNF_HDMI_VENDORSPEC_INFOFRAME_S;

/**HDMI InfoFrame unit struct*/
/**CNcomment: HDMI \D0\C5Ϣ֡\C1\AA\BA϶\A8\D2\E5\CC\E5 */
typedef union hiUNF_HDMI_INFOFRAME_UNIT_U
{
    HI_UNF_HDMI_AVI_INFOFRAME_VER2_S   stAVIInfoFrame;      /**<AVI FrameInfo*//**<CNcomment:AVI\D0\C5Ϣ֡ */
    HI_UNF_HDMI_AUD_INFOFRAME_VER1_S   stAUDInfoFrame;      /**<Audio FrameInfo*//**<CNcomment:AUD\D0\C5Ϣ֡ */
    HI_UNF_HDMI_SPD_INFOFRAME_S        stSPDInfoFrame;      /**<SPD FrameInfo*//**<CNcomment:SPD\D0\C5Ϣ֡ */
    HI_UNF_HDMI_MPEGSOURCE_INFOFRAME_S stMPEGSourceInfoFrame;/**<MPEGSource FrameInfo*//**<CNcomment:MPEGSource\D0\C5Ϣ֡ */
    HI_UNF_HDMI_VENDORSPEC_INFOFRAME_S stVendorSpecInfoFrame;/**<VS FrameInfo*//**<CNcomment:VS\D0\C5Ϣ֡ */
}HI_UNF_HMDI_INFORFRAME_UNIT_U;

/**HDMI InfoFrame struct */
/**CNcomment: HDMI \D0\C5Ϣ֡\CA\FD\BEݽṹ */
typedef struct hiUNF_HDMI_INFOFRAME_S
{
    HI_UNF_HDMI_INFOFRAME_TYPE_E    enInfoFrameType;  /**<InfoFrame type*//**CNcomment:<InfoFrame\C0\E0\D0\CD */
    HI_UNF_HMDI_INFORFRAME_UNIT_U   unInforUnit;      /**<InfoFrame unit data*//**CNcomment:<InfoFrame\CA\FD\BE\DD */
}HI_UNF_HDMI_INFOFRAME_S;


/* CEC */
/** CEC interrelated Opcode:Please refer to CEC 15 Message Descriptions */
/** CNcomment: CEC \CF\E0\B9صĲ\D9\D7\F7\C2\EB */

/* General Protocol messages */

/**"Feature Abort" Used as a response to indicate that the device does not support the requested message type, or that it cannot execute it at the present time. */
/**CNcomment:"Feature Abort"\CF\FBϢ\B1\ED\C3\F7\C9豸\B2\BB֧\B3ָ\C3\D0\C5Ϣ\B5Ļظ\B4\A3\AC\BB\F2\B5\B1ǰû\B7\A8\B4\A6\C0\ED*/
#define CEC_OPCODE_FEATURE_ABORT                  0X00
/**"Abort" Message This message is reserved for testing purposes.*/
/**CNcomment:"Abort"\CF\FBϢ\CA\C7רΪ\B2\E2\CAԱ\A3\C1\F4\B5\C4*/
#define CEC_OPCODE_ABORT_MESSAGE                  0XFF

/* One Touch Play Feature*/

/**"Active Source" Used by a new source to indicate that it has started to transmit a stream OR used in response to a "Request Active Source"*/
/**CNcomment:"Active Source"\CF\FBϢ˵\C3\F7Դ\B6\CB\C9豸\D5\FD\D4ڷ\A2\CB\CDһ\CC\F5\C2\EB\C1\F7\BB\F2\D5߻ظ\B4"Request Active Source"\CF\FBϢ*/
#define CEC_OPCODE_ACTIVE_SOURCE                  0X82
/**"Image View On" Sent by a source device to the TV whenever it enters the active state (alternatively it may send "Text View On").*/
/**CNcomment:\B5\B1Դ\B6\CB\C9豸\BD\F8\C8뼤\BB\EE״̬ʱ\A3\AC\BB\E1\B8\F8TV\B7\A2\CB\CDһ\B4\CE"Image View On"\CF\FBϢ*/
#define CEC_OPCODE_IMAGE_VIEW_ON                  0X04
/**"Text View On" As "Image View On", but should also remove any text, menus and PIP windows from the TV's display.*/
/**CNcomment:"Text View On" \BA\CD"Image View On"ָ\C1\EE\CF\E0\CBƣ\AC\B5\ABͬʱ\BB\E1\B4\D3TV\BB\AD\C3\E6\C9Ϲر\D5\CE\C4\D7֣\AC\B2˵\A5\BAͻ\AD\D6л\AD\B4\B0\BF\DA*/
#define CEC_OPCODE_TEXT_VIEW_ON                   0X0D

/* Routing Control Feature*/

/**"Inactive Source" Used by the currently active source to inform the TV that it has no video to be presented to the user, or is going into standby as the result of a local user command on the device. */
/**CNcomment: "Inactive Source"\CF\FBϢ\B1\ED\C3\F7\B5\B1ǰ\CE\DE\C2\EB\C1\F7\B2\A5\B7Ż\F2\D5\DF\D2\F2\D3û\A7\B2\D9\D7\F7\A3\AC\C9豸Ҫ\BD\F8\C8\EB\B4\FD\BB\FA״̬*/
#define CEC_OPCODE_INACTIVE_SOURCE                0X9D
/**"Request Active Source" Used by a new device to discover the status of the system.*/
/**CNcomment: "Request Active Source"\CF\FBϢ\D3\C3\D3\DA֪ͨϵͳ\CC\ED\BC\D3\C1\CBһ\B8\F6\D0\C2\C9豸*/
#define CEC_OPCODE_REQUEST_ACTIVE_SOURCE          0X85
/**"Routing Change" Sent by a CEC Switch when it is manually switched to inform all other devices on the network that the active route below the switch has changed. */
/**CNcomment: \B5\B1CECת\BD\D3\C6\F7\BC\EC\B2⵽\D7\D3\C9豸\C1б\ED\B7\A2\C9\FA\B1仯ʱ\A3\AC\BB\E1֪ͨ\CB\F9\D3л\D7\D3\C9豸 "Routing Change"\CF\FBϢ*/
#define CEC_OPCODE_ROUTING_CHANGE                 0X80
/**"Routing Information" Sent by a CEC Switch to indicate the active route below the switch.*/
/**CNcomment: CECת\BD\D3\C6\F7\B7\A2\CB\CD"Routing Information"\CF\FBϢ\C0\B4\BC\EC\B2\E2\D7\D3\CD\F8\C2\E7\CF»\D7\D3\C9豸*/
#define CEC_OPCODE_ROUTING_INFORMATION            0X81
/**"Set Stream Path" Used by the TV to request a streaming path from the specified physical address.*/
/**CNcomment: TV\B4\D3һ\B8\F6\CCض\A8\B5\C4\C9豸\C9ϻ\F1ȡ\C2\EB\C1\F7·\BE\B6 */
#define CEC_OPCODE_SET_STREAM_PATH                0X86

/* Standby Feature*/

/**"Standby" Switches one or all devices into standby mode. Can be used as a broadcast message or be addressed to a specific device.See section CEC 13.3 for important notes on the use of this message */
/**CNcomment: "Standby"\CF\FBϢ\C4\DCʹһ\B8\F6\BB\F2\B6\E0\B8\F6\C9豸\BD\F8\C8\EB\B4\FD\BB\FA״̬\A1\A3\BF\C9\D3ù㲥\BB\F2\D5߸\F8\CCض\A8\B5\C4\C9豸\B5\A5\B6\C0\B7\A2\CB\CD*/
#define CEC_OPCODE_STANDBY                        0X36

/* One Touch Record Feature*/

/**"Record Off" Requests a device to stop a recording. */
/**CNcomment: "Record Off"\C4\DCʹһ\B8\F6\C9豸ֹͣ¼\CF\F1*/
#define CEC_OPCODE_RECORD_OFF                     0X0B
/**"Record On" Attempt to record the specified source. */
/**CNcomment: "Record On"\CF\FBϢ\D3\C3\D3ڳ\A2\CA\D4\C8\C3һ\B8\F6\CCض\A8\B5\C4Դ¼\CF\F1*/
#define CEC_OPCODE_RECORD_ON                      0X09
/**"Record Status" Used by a Recording Device to inform the initiator of the message "Record On" about its status. */
/**CNcomment: \BF\C9¼\CF\F1\C9豸\B7\A2\CB\CD"Record Status"\CF\FBϢ\BA\CD״̬\B8\F8\B7\A2\C6\F0"Record On"\CF\FBϢ\B5ĵ\C4\C9豸*/
#define CEC_OPCODE_RECORD_STATUS                  0X0A
/**"Record TV Screen" Request by the Recording Device to record the presently displayed source. */
/**CNcomment: "Record TV Screen"\CF\FBϢ\D3\C3\D3\DA\C7\EB\C7\F3¼\CF\F1\C9豸\BC\C7¼\B5\B1ǰ\CF\D4ʾ\B5\C4\D7\CAԴ*/
#define CEC_OPCODE_RECORD_TV_SCREEN               0X0F

/* Timer Programming Feature*/

/**"Clear Analogue Timer" Used to clear an Analogue timer block of a device. */
/**CNcomment: \C7\E5\BF\D5ģ\C4ⶨʱ\C6\F7\C9豸*/
#define CEC_OPCODE_CLEAR_ANALOGUE_TIMER           0X33
/**"Clear Digital Timer" Used to clear a Digital timer block of a device. */
/**CNcomment: \C7\E5\BF\D5\CA\FD\D7ֶ\A8ʱ\C6\F7\C9豸*/
#define CEC_OPCODE_CLEAR_DIGITAL_TIMER            0X99
/**"Clear External Timer" Used to clear an External timer block of a device. */
/**CNcomment: \C7\E5\BF\D5\CDⲿ\B6\A8ʱ\C6\F7\C9豸*/
#define CEC_OPCODE_CLEAR_EXTERNAL_TIMER           0XA1
/**"Set Analogue Timer" Used to set a single timer block on an Analogue Recording Device. */
/**CNcomment: \D4\DAģ\C4ⶨʱ\C6\F7\C9豸\C9\CF\C9\E8\D6ö\A8ʱ\C6\F7*/
#define CEC_OPCODE_SET_ANALOGUE_TIMER             0X34
/**"Set Digital Timer" Used to set a single timer block on a Digital Recording Device. */
/**CNcomment: \D4\DA\CA\FD\D7ֶ\A8ʱ\C6\F7\C9豸\C9\CF\C9\E8\D6ö\A8ʱ\C6\F7*/
#define CEC_OPCODE_SET_DIGITAL_TIMER              0X97
/**"Set External Timer" Used to set a single timer block to record from an external device. */
/**CNcomment: \D4\DA\CDⲿ\B6\A8ʱ\C6\F7\C9豸\C9\CF\C9\E8\D6ö\A8ʱ\C6\F7*/
#define CEC_OPCODE_SET_EXTERNAL_TIMER             0XA2
/**"Set Timer Program Title" Used to set the name of a program associated with a timer block. Sent directly after sending a "Set Analogue Timer" or "Set Digital Timer" message. The name is then associated with that timer block. */
/**CNcomment: \B5\B1\B7\A2\CB\CD\CD\EA"Set Analogue Timer" \BB\F2"Set Digital Timer"\CF\FBϢ\BA\F3\B7\A2\CB\CDһ\B8\F6\C3\FB\B3\C6\D3\C3\D3ڳ\CC\D0\F2\BAͶ\A8ʱ\C6\F7ģ\BF\E9\B9\D8\C1\AA */
#define CEC_OPCODE_SET_TIMER_PROGRAM_TITLE        0X67
/**"Timer Cleared Status" Used to give the status of a "Clear Analogue Timer", "Clear Digital Timer" or "Clear External Timer" message. */
/**CNcomment: "Timer Cleared Status"\CF\FBϢ\D3\C3\D3ڷ\A2\CB\CD"Clear Analogue Timer"\A3\AC"Clear Digital Timer"\A3\AC"Clear External Timer"֮\BA\F3\B5\C4״̬*/
#define CEC_OPCODE_TIMER_CLEARED_STATUS           0X43
/**"Timer Status" Used to send timer status to the initiator of a "Set Timer" message. */
/**CNcomment: "Timer Status"\CF\FBϢ\D3\C3\D3ڸ\F8Set Timer"\CF\FBϢ\B5ķ\A2\C6\F0\D5߷\A2\CBͶ\A8ʱ\C6\F7״̬*/
#define CEC_OPCODE_TIMER_STATUS                   0X35

/* System Information Feature*/

/**"CEC Version" Used to indicate the supported CEC version, in response to a "Get CEC Version" */
/**CNcomment: "CEC Version"\CF\FBϢ\D3\C3\D3ڷ\A2\CB\CD\C9豸\C9ϵ\C4CEC\B0汾\D0\C5Ϣ\C0\B4\BBظ\B4"Get CEC Version"\CF\FBϢ*/
#define CEC_OPCODE_CEC_VERSION                    0X9E
/**"Get CEC Version" Used by a device to enquire which version of CEC the target supports */
/**CNcomment: "Get CEC Version"\D3\C3\D3\DAһ\B8\F6\C9豸\BB\F1ȡ\B4\D3\C9豸\B5\C4CEC\B0汾\D0\C5Ϣ*/
#define CEC_OPCODE_GET_CEC_VERSION                0X9F
/**"Give Physical Address" A request to a device to return its physical address. */
/**CNcomment: \CF\F2һ\B8\F6\C9豸\C7\EB\C7\F3\BB\F1ȡ\B8\C3\C9豸\B5\C4\CE\EF\C0\ED\B5\D8ַ*/
#define CEC_OPCODE_GIVE_PHYSICAL_ADDRESS          0X83
/**"Report Physical Address" Used to inform all other devices of the mapping between physical and logical address of the initiator.*/
/**CNcomment: \CF\F2ͬһ\CD\F8\C2\E7\CF\C2\C6\E4\CB\FB\CB\F9\D3\D0\C9豸\B7\A2\CB\CD\CE\EF\C0\ED\B5\D8ַ\BA\CD\C2߼\AD\B5\D8ַ*/
#define CEC_OPCODE_REPORT_PHYSICAL_ADDRESS        0X84
/**"Get Menu Language" Sent by a device capable of character generation (for OSD and Menus) to a TV in order to discover the currently selected Menu language.Also used by a TV during installation to discover the currently set menu language of other devices.*/
/**CNcomment: "Get Menu Language"\D3\C3\D3ڻ\F1ȡTv\B6\CB\C4\DC\C1\A6\BC\AF\A3\AC\D3\C3\D3\DA\CC滻\B5\B1ǰ\B5Ĳ˵\A5\D3\EF\D1\D4\C0\E0\D0ͣ\BBҲ\BF\C9\D3\C3\D3\DATV\C9豸\C6\F4\B6\AFʱ\A3\AC\C9\E8\D6\C3\C6\E4\CB\FC\C9豸\B5Ĳ˵\A5\D3\EF\D1\D4*/
#define CEC_OPCODE_GET_MENU_LANGUAGE              0X91
/**"Set Menu Language" Used by a TV or another device to indicate the menu language. */
/**CNcomment: "Set Menu Language"\D3\C3\D3\DATv\BB\F2\C6\E4\CB\FB\C9豸\A3\AC\C9\E8\D6ò˵\A5\D3\EF\D1\D4*/
#define CEC_OPCODE_SET_MENU_LANGUAGE              0X32

/*  Deck Control Feature*/

/**"Deck Control" Used to control a device's media functions. */
/**CNcomment: "Deck control"\CF\FBϢ\D3\C3\D3ڿ\D8\D6\C6һ\B8\F6\C9豸\B5Ķ\E0ý\CC幦\C4\DC*/
#define CEC_OPCODE_DECK_CONTROL                   0X42
/**"Deck Status" Used to provide a deck's status to the initiator of the "Give Deck Status" message. */
/**CNcomment: "Deck Status "\CF\FBϢ\D3\C3\D3ڻظ\B4"Give Deck Status"\CF\FBϢ\B5ķ\A2\C6\F0\D5\DFDeck\B5\C4״̬*/
#define CEC_OPCODE_DECK_STATUS                    0X1B
/**"Give Deck Status" Used to request the status of a device, regardless of whether or not it is the current active source. */
/**CNcomment: "Give Deck Status"\CF\FBϢ\C7\EB\C7\F3\BB\F1ȡĿ\B1\EA\C9豸\B5\C4״̬\A3\AC\B6\F8\B2\BB\B9\DCĿ\B1\EA\C9豸Ŀǰ\CAǲ\BB\CAǼ\A4\BB\EE\B5\C4*/
#define CEC_OPCODE_GIVE_DECK_STATUS               0X1A
/**"Play" Used to control the playback behaviour of a source device. */
/**CNcomment: "Play"\CF\FBϢ\D3\C3\D3ڿ\D8\D6\C6Դ\C9豸\B2\A5\B7\C5*/
#define CEC_OPCODE_PLAY                           0X41

/* Tuner Control Feature*/

/**"Give Tuner Device Status" Used to request the status of a tuner device. */
/**CNcomment: "Give Tuner Device Status"\D3\C3\D3ڻ\F1ȡ\B5\E7\CAӵ\F7г\C6\F7\B5\C4״̬*/
#define CEC_OPCODE_GIVE_TUNER_DEVICE_STATUS       0X08
/**"Select Analogue Service" Directly selects an Analogue TV service */
/**CNcomment: "Select Analogue Service"\CF\FBϢ\D3\C3\D3\DAֱ\BD\D3ѡ\D4\F1һ\B8\F6ģ\C4\E2\B5\E7\CAӵķ\FE\CE\F1\CF\EE*/
#define CEC_OPCODE_SELECT_ANALOGUE_SERVICE        0X92
/**"Select Digital Service" Directly selects a Digital TV, Radio or Data Broadcast Service */
/**CNcomment: "Select Digital Service"\CF\FBϢ\D3\C3\D3\DAֱ\BD\D3ѡ\D4\F1һ\B8\F6\CA\FD\D7ֵ\E7\CAӵķ\FE\CE\F1\CF\EE*/
#define CEC_OPCODE_SELECT_DIGITAL_SERVICE         0X93
/**"Tuner Device Status" Use by a tuner device to provide its status to the initiator of the "Give Tuner Device Status" message. */
/**CNcomment: "Tuner Device Status"\CF\FBϢ\D3\C3\D3ڵ\E7\CAӵ\F7г\C6\F7\B8\F8" Give Tuner Device Status"\CF\FBϢ\B5ķ\A2\C6\F0\B6˻ظ\B4*/
#define CEC_OPCODE_TUNER_DEVICE_STATUS            0X07
/**"Tuner Step Decrement" Used to tune to next lowest service in a tuner's service list. Can be used for PIP. */
/**CNcomment: "Tuner Step Decrement"\CF\FBϢ\D3\C3\D3ڰѴε͵ķ\FE\CE\F1\CF\EE\B7\C5\C8\EB\B5\F7г\C6\F7\B5ķ\FE\CE\F1\C1б\ED\A3\AC\C4\DC\D3\C3\D3ڻ\AD\D6л\AD*/
#define CEC_OPCODE_TUNER_STEP_DECREMENT           0X06
/**"Tuner Step Increment" Used to tune to next highest service in a tuner's service list. Can be used for PIP. */
/**CNcomment: "Tuner Step Decrement"\CF\FBϢ\D3\C3\D3ڰѴθߵķ\FE\CE\F1\CF\EE\B7\C5\C8\EB\B5\F7г\C6\F7\B5ķ\FE\CE\F1\C1б\ED\A3\AC\C4\DC\D3\C3\D3ڻ\AD\D6л\AD*/
#define CEC_OPCODE_TUNER_STEP_INCREMENT           0X05

/* Vendor Specific Command*/

/**"Device Vendor ID" Reports the vendor ID of this device. */
/**CNcomment: "Device Vendor ID"\CF\FBϢ\D3\C3\D3ڱ\A8\B8\E6\B4\CB\C9豸\B5Ĺ\A9Ӧ\C9\CCID*/
#define CEC_OPCODE_DEVICE_VENDOR_ID               0X87
/**"Give Device Vendor ID" Requests the Vendor ID from a device. */
/**CNcomment: "Give Device Vendor ID"\CF\FBϢ\D3\C3\D3\DA\C7\EB\C7\F3\B4\CB\C9豸\B5Ĺ\A9Ӧ\C9\CCID*/
#define CEC_OPCODE_GIVE_DEVICE_VENDOR_ID          0X8C
/**"Vendor Command" Allows vendor specific commands to be sent between two devices. */
/**CNcomment: "Vendor Command"\D3\C3\D3\DA\C1\BD\B8\F6\C9豸֮\BC以\CF෢\CB͹\A9Ӧ\C9̶\A8\D6\C6\CF\FBϢ*/
#define CEC_OPCODE_VENDOR_COMMAND                 0X89
/**"Vendor Command With ID" Allows vendor specific commands to be sent between two devices or broadcast. */
/**CNcomment: "Vendor Command With ID"\D3\C3\D3\DA\C1\BD\B8\F6\C9豸֮\BC\E4\BB\F2\B9㲥\D0\CEʽ\B7\A2\CB͹\A9Ӧ\C9̶\A8\D6\C6\CF\FBϢ*/
#define CEC_OPCODE_VENDOR_COMMAND_WITH_ID         0XA0
/**"Vendor Remote Button Down" Indicates that a remote control button has been depressed. */
/**CNcomment: "Vendor Remote Button Down"\CF\FBϢ\B1\EDʾ\A3\ACң\BF\D8\C6\F7\D3а\B4\BC\FC\B0\B4\CF\C2\C0\B4*/
#define CEC_OPCODE_VENDOR_REMOTE_BUTTON_DOWN      0X8A
/**"Vendor Remote Button Up" Indicates that a remote control button (the last button pressed indicated by the Vendor Remote Button Down message) has been released. */
/**CNcomment: "Vendor Remote Button Up"\CF\FBϢ\B1\EDʾ "Vendor Remote Button Down"\CF\FBϢ\D7\EE\BA\F3һ\B4α\EDʾ\B9\FD\B5İ\B4\BC\FC\B1\BB\CAͷ\C5\C1\CB*/
#define CEC_OPCODE_VENDOR_REMOTE_BUTTON_UP        0X8B

/* OSD Display Feature*/

/**"Set OSD String" Used to send a text message to output on a TV. */
/**CNcomment: "Set OSD String"\CF\FBϢ\BF\C9\D2Է\A2\CB\CDһ\B6\CE\CE\C4\D7\D6\CF\FBϢ\C8\C3\CB\FC\CF\D4ʾ\D4ڵ\E7\CAӻ\FA\C9\CF*/
#define CEC_OPCODE_SET_OSD_STRING                 0X64
/**"Give OSD Name" Used to request the preferred OSD name of a device for use in menus associated with that device. */
/**CNcomment:\C7\EB\C7\F3\CA\D7ѡ\B5Ĺ\D8\C1\AA\C9豸\B2˵\A5\CF\D4ʾ\B5\C4\C3\FB\D7\D6 */
#define CEC_OPCODE_GIVE_OSD_NAME                  0X46
/**"Set OSD Name" Used to set the preferred OSD name of a device for use in menus associated with that device. */
/**CNcomment:\C9\E8\D6\C3\CA\D7ѡ\B9\D8\C1\AA\C9豸\B2˵\A5\CF\D4ʾ\B5\C4\C3\FB\D7\D6 */
#define CEC_OPCODE_SET_OSD_NAME                   0X47

/* Device Menu Control Feature*/

/**"Menu Request" A request from the TV for a device to show/remove a menu or to query if a device is currently showing a menu. */
/**CNcomment: "Menu Request"\CF\FBϢ\D3\C3\D3ڵ\E7\CA\D3\C7\EB\C7\F3һ\B8\F6\C9豸\CF\D4ʾ/\B9رղ˵\A5\BB\F2ѯ\CEʸ\C3\C9豸\B5\B1ǰ\D3\D0û\D3в˵\A5\CF\D4ʾ*/
#define CEC_OPCODE_MENU_REQUEST                   0X8D
/**"Menu Status" Used to indicate to the TV that the device is showing/has removed a menu and requests the remote control keys to be passed though. */
/**CNcomment: "Menu Status"\CF\FBϢ\D3\C3\D3ڻظ\B4\B5\E7\CAӶ˵\B1ǰ\D5\FD\CF\D4ʾ/\D2Ƴ\FD\C1˲˵\A5\A3\AC\B2\A2͸\B4\ABң\BF\D8\C6\F7ָ\C1\EE*/
#define CEC_OPCODE_MENU_STATUS                    0X8E
/**"User Control Pressed" Used to indicate that the user pressed a remote control button or switched from one remote control button to another. */
/**CNcomment: "User Control Pressed"\B1\EDʾ\D3û\A7\B0\B4\C1\CBһ\B8\F6ң\BF\D8\C6\F7\B0\B4\BC\FC\BB\F2\B4\D3ĳһ\B8\F6\B0\B4\BC\FC\BB\BB\B5\BD\C1\EDһ\B8\F6\B0\B4\BC\FC.Ҳ\BF\C9\D2\D4\D3\C3\D3\DA\D3û\A7\BC\E4\BDӷ\A2\C6\F0\B5\C4ָ\C1\EE*/
#define CEC_OPCODE_USER_CONTROL_PRESSED           0X44
/**"User Control Released" Indicates that user released a remote control button (the last one indicated by the "User Control Pressed" message) */
/**CNcomment: "User Control Released"\B1\EDʾ\D3û\A7\CAͷ\C5\C1\CB"User Control Released"\CF\FBϢָ\B6\A8\B5\C4ң\BF\D8\C6\F7\B0\B4\BC\FC.Ҳ\BF\C9\D2\D4\D3\C3\D3\DA\D3û\A7\BC\E4\BDӷ\A2\C6\F0\B5\C4ָ\C1\EE*/
#define CEC_OPCODE_USER_CONTROL_RELEASED          0X45

/* Power Status Feature*/

/**"Give Device Power Status" Used to determine the current power status of a target device */
/**CNcomment: "Give Device Power Status"\CF\FBϢ\D3\C3\D3ڻ\F1ȡĿ\B1\EA\C9豸\B5\B1ǰ\B5ĵ\E7Դ״̬*/
#define CEC_OPCODE_GIVE_DEVICE_POWER_STATUS       0X8F
/**"Report Power Status" Used to inform a requesting device of the current power status */
/**CNcomment: "Report Power Status"\CF\FBϢ\D3\C3\D3ڷ\A2\CB͵\B1ǰ\B5ĵ\E7Դ״̬\BBظ\B4\C7\EB\C7\F3\C9豸*/
#define CEC_OPCODE_REPORT_POWER_STATUS            0X90

/* System Audio Control Feature*/

/**"Give Audio Status" Requests an amplifier to send its volume and mute status */
/**CNcomment: "Give Audio Status"\CF\FBϢ\C7\EB\C7\F3\BB\F1ȡ\C0\A9\D2\F4\C6\F7\B5\C4\D2\F4\C1\BF\BA;\B2\D2\F4״̬*/
#define CEC_OPCODE_GIVE_AUDIO_STATUS              0X71
/**"Give System Audio Mode Status" Requests the status of the System Audio Mode */
/**CNcomment: "Give System Audio Mode Status"\CF\FBϢ\C7\EB\C7\F3ϵͳ\D2\F4Ƶ\B5\C4״̬*/
#define CEC_OPCODE_GIVE_SYSTEM_AUDIO_MODE_STATUS  0x7D
/**"Report Audio Status" Reports an amplifier's volume and mute status */
/**CNcomment: "Report Audio Status"\CF\FBϢ\D3\C3\D3ڷ\A2\CB\CD\C0\A9\D2\F4\C6\F7\B5\C4\D2\F4\C1\BF\BA;\B2\D2\F4״̬*/
#define CEC_OPCODE_REPORT_AUDIO_STATUS            0X7A
/**"Set System Audio Mode" Turns the System Audio Mode On or Off. */
/**CNcomment: "Set System Audio Mode"\CF\FBϢ\D3\C3\D3ڴ\F2\BF\AA/\B9ر\D5ϵͳ\D2\F4Ƶ\B9\A6\C4\DC*/
#define CEC_OPCODE_SET_SYSTEM_AUDIO_MODE          0X72
/**"System Audio Mode Request" A device implementing System Audio Control and which has volume control RC buttons (eg TV or STB) requests to use System Audio Mode to the amplifier */
/**CNcomment: ʹ\D3\C3\D2\F4\C1\BF\BF\D8\D6ư\B4ť(stb\BB\F2\D5\DFtv)\D0\E8Ҫ\D1\EF\C9\F9\C6\F7\BD\F8\C8\EB System Audio Mode*/
#define CEC_OPCODE_SYSTEM_AUDIO_MODE_REQUEST      0X70
/**"System Audio Mode Status" Reports the current status of the System Audio Mode */
/**CNcomment: "System Audio Mode Status"\CF\FBϢ\D3\C3\D3ڷ\A2\CB\CDϵͳ\D2\F4Ƶ\B5\B1ǰ\B5\C4״̬*/
#define CEC_OPCODE_SYSTEM_AUDIO_MODE_STATUS       0X7E

/* Audio Rate Control Feature*/

/**"Set Audio Rate" Used to control audio rate from Source Device. */
/**CNcomment: "Set Audio Rate"\CF\FBϢ\D3\C3\D3ڿ\D8\D6\C6Դ\B6\CB\C9豸\B5\C4\D2\F4Ƶ\B2\C9\D1\F9\C2\CA*/
#define CEC_OPCODE_SET_AUDIO_RATE                 0X9A

/**POLL message have no opcode, So, we just use this value */
/**CNcomment: "POLL"\CF\FBϢû\D3в\D9\D7\F7\C2룬\CE\D2\C3ǽ\F6\BD\F6ֻ\CA\C7ʹ\D3ø\C3ֵ*/
#define CEC_OPCODE_POLLING_MESSAGE                0XFE

/**HDMI CEC logical address,please reference  HDMI specification 1.4a*/
/**CNcomment: HDMI CEC\C2߼\AD\B5\D8ַ\A3\AC\C7\EB\B2ο\BCHDMI 1.4aЭ\D2\E9 */
typedef enum hiUNF_CEC_LOGICALADD_S
{
    HI_UNF_CEC_LOGICALADD_TV               = 0X00, /**<TV*//**CNcomment:<\B5\E7\CA\D3 */
    HI_UNF_CEC_LOGICALADD_RECORDDEV_1      = 0X01, /**<Record device 1*//**CNcomment:<¼\CF\F1\BB\FA 1 */
    HI_UNF_CEC_LOGICALADD_RECORDDEV_2      = 0X02, /**<Record device 2*//**CNcomment:<¼\CF\F1\BB\FA 2 */
    HI_UNF_CEC_LOGICALADD_TUNER_1          = 0X03, /**<Tuner 1*//**CNcomment:<\B8\DFƵͷ 1*/
    HI_UNF_CEC_LOGICALADD_PLAYDEV_1        = 0X04, /**<play device 1*//**CNcomment:<\B2\A5\B7\C5\C9豸 1 */
    HI_UNF_CEC_LOGICALADD_AUDIOSYSTEM      = 0X05, /**<audio system*//**CNcomment:<\D2\F4Ƶϵͳ */
    HI_UNF_CEC_LOGICALADD_TUNER_2          = 0X06, /**<tuner 2*//**CNcomment:<\B8\DFƵͷ 2 */
    HI_UNF_CEC_LOGICALADD_TUNER_3          = 0X07, /**<tuner 3*//**CNcomment:<\B8\DFƵͷ 3 */
    HI_UNF_CEC_LOGICALADD_PLAYDEV_2        = 0X08, /**<play device 2*//**CNcomment:<\B2\A5\B7\C5\C9豸 2 */
    HI_UNF_CEC_LOGICALADD_RECORDDEV_3      = 0X09, /**<Record device 3*//**CNcomment:<¼\CF\F1\BB\FA 3 */
    HI_UNF_CEC_LOGICALADD_TUNER_4          = 0X0A, /**<tuner 4*//**CNcomment:<\B8\DFƵͷ 4 */
    HI_UNF_CEC_LOGICALADD_PLAYDEV_3        = 0X0B, /**<play device 3*//**CNcomment:<\B2\A5\B7\C5\C9豸 3 */
    HI_UNF_CEC_LOGICALADD_RESERVED_1       = 0X0C, /**<reserved 1*//**CNcomment:<\B1\A3\C1\F4\CF\EE 1 */
    HI_UNF_CEC_LOGICALADD_RESERVED_2       = 0X0D, /**<reserved 2*//**CNcomment:<\B1\A3\C1\F4\CF\EE 2 */
    HI_UNF_CEC_LOGICALADD_SPECIALUSE       = 0X0E, /**<special use*//**CNcomment:<\CC\D8\CA\E2\D3\C3; */
    HI_UNF_CEC_LOGICALADD_BROADCAST        = 0X0F, /**<broadcast*//**CNcomment:<\B9㲥 */
    HI_UNF_CEC_LOGICALADD_BUTT
}HI_UNF_CEC_LOGICALADD_S;

/**HDMI CEC command type,please reference  HDMI specification 1.4a*/
/**CNcomment: HDMI CEC\C3\FC\C1\EE\C0\E0\D0ͣ\AC\C7\EB\B2ο\BCHDMI 1.4aЭ\D2\E9 */
typedef enum hiUNF_CEC_CMDTYPE_E
{
    HI_UNF_CEC_STRUCTCOMMAND,                    /**<CEC struct command*//**<CNcomment:CEC \BDṹ\C3\FC\C1\EE */
    HI_UNF_CEC_RAWCOMMAND,                       /**<CEC raw command*//**<CNcomment:CEC ԭʼ\C3\FC\C1\EE */
    HI_UNF_CEC_BUTT
}HI_UNF_CEC_CMDTYPE_E;

/**HDMI CEC Raw Data struct,please reference  HDMI specification 1.4a*/
/**CNcomment: HDMI CECԭʼ\CA\FD\BEݽṹ\CC壬\C7\EB\B2ο\BCHDMI 1.4aЭ\D2\E9 */
typedef struct hiUNF_CEC_RAWDATA_S
{
    HI_U8                              u8Length;  /**<CEC raw data lengh*//**<CNcomment:cec \D3\D0Ч\B2\CE\CA\FD\B8\F6\CA\FD */
    HI_U8                              u8Data[15];     /**<CEC raw data*//**<CNcomment:CEC \B2\CE\CA\FD\BDṹ\CC\E5 */
}HI_UNF_CEC_RAWDATA_S;

/**HDMI CEC user Interface Command Opcode,please reference  HDMI specification 1.4a*/
/**CNcomment: HDMI CEC \D3û\A7\BDӿڲ\D9\D7\F7ָ\C1\C7\EB\B2ο\BCHDMI 1.4aЭ\D2\E9 */
typedef enum hiUNF_CEC_UICMD_E
{
    HI_UNF_CEC_UICMD_SELECT                      = 0x00,
    HI_UNF_CEC_UICMD_UP                          = 0x01,
    HI_UNF_CEC_UICMD_DOWN                        = 0x02,
    HI_UNF_CEC_UICMD_LEFT                        = 0x03,
    HI_UNF_CEC_UICMD_RIGHT                       = 0x04,
    HI_UNF_CEC_UICMD_RIGHT_UP                    = 0x05,
    HI_UNF_CEC_UICMD_RIGHT_DOWN                  = 0x06,
    HI_UNF_CEC_UICMD_LEFT_UP                     = 0x07,
    HI_UNF_CEC_UICMD_LEFT_DOWN                   = 0x08,
    HI_UNF_CEC_UICMD_ROOT_MENU                   = 0x09,
    HI_UNF_CEC_UICMD_SETUP_MENU                  = 0x0A,
    HI_UNF_CEC_UICMD_CONTENTS_MENU               = 0x0B,
    HI_UNF_CEC_UICMD_FAVORITE_MENU               = 0x0C,
    HI_UNF_CEC_UICMD_EXIT                        = 0x0D,
    HI_UNF_CEC_UICMD_NUM_0                       = 0x20,
    HI_UNF_CEC_UICMD_NUM_1                       = 0x21,
    HI_UNF_CEC_UICMD_NUM_2                       = 0x22,
    HI_UNF_CEC_UICMD_NUM_3                       = 0x23,
    HI_UNF_CEC_UICMD_NUM_4                       = 0x24,
    HI_UNF_CEC_UICMD_NUM_5                       = 0x25,
    HI_UNF_CEC_UICMD_NUM_6                       = 0x26,
    HI_UNF_CEC_UICMD_NUM_7                       = 0x27,
    HI_UNF_CEC_UICMD_NUM_8                       = 0x28,
    HI_UNF_CEC_UICMD_NUM_9                       = 0x29,
    HI_UNF_CEC_UICMD_DOT                         = 0x2A,
    HI_UNF_CEC_UICMD_ENTER                       = 0x2B,
    HI_UNF_CEC_UICMD_CLEAR                       = 0x2C,
    HI_UNF_CEC_UICMD_NEXT_FAVORITE               = 0x2F,
    HI_UNF_CEC_UICMD_CHANNEL_UP                  = 0x30,
    HI_UNF_CEC_UICMD_CHANNEL_DOWN                = 0x31,
    HI_UNF_CEC_UICMD_PREVIOUS_CHANNEL            = 0x32,
    HI_UNF_CEC_UICMD_SOUND_SELECT                = 0x33,
    HI_UNF_CEC_UICMD_INPUT_SELECT                = 0x34,
    HI_UNF_CEC_UICMD_DISPLAY_INFORMATION         = 0x35,
    HI_UNF_CEC_UICMD_HELP                        = 0x36,
    HI_UNF_CEC_UICMD_PAGE_UP                     = 0x37,
    HI_UNF_CEC_UICMD_PAGE_DOWN                   = 0x38,
    HI_UNF_CEC_UICMD_POWER                       = 0x40,
    HI_UNF_CEC_UICMD_VOLUME_UP                   = 0x41,
    HI_UNF_CEC_UICMD_VOLUME_DOWN                 = 0x42,
    HI_UNF_CEC_UICMD_MUTE                        = 0x43,
    HI_UNF_CEC_UICMD_PLAY                        = 0x44,
    HI_UNF_CEC_UICMD_STOP                        = 0x45,
    HI_UNF_CEC_UICMD_PAUSE                       = 0x46,
    HI_UNF_CEC_UICMD_RECORD                      = 0x47,
    HI_UNF_CEC_UICMD_REWIND                      = 0x48,
    HI_UNF_CEC_UICMD_FAST_FORWARD                = 0x49,
    HI_UNF_CEC_UICMD_EJECT                       = 0x4A,
    HI_UNF_CEC_UICMD_FORWARD                     = 0x4B,
    HI_UNF_CEC_UICMD_BACKWARD                    = 0x4C,
    HI_UNF_CEC_UICMD_STOP_RECORD                 = 0x4D,
    HI_UNF_CEC_UICMD_PAUSE_RECORD                = 0x4E,
    HI_UNF_CEC_UICMD_ANGLE                       = 0x50,
    HI_UNF_CEC_UICMD_SUBPICTURE                  = 0x51,
    HI_UNF_CEC_UICMD_VIDEO_ON_DEMAND             = 0x52,
    HI_UNF_CEC_UICMD_ELECTRONIC_PROGRAM_GUIDE    = 0x53,
    HI_UNF_CEC_UICMD_TIMER_PROGRAMMING           = 0x54,
    HI_UNF_CEC_UICMD_INITIAL_CONFIGURATION       = 0x55,
    HI_UNF_CEC_UICMD_PLAY_FUNCTION               = 0x60,
    HI_UNF_CEC_UICMD_PAUSE_PLAY_FUNCTION         = 0x61,
    HI_UNF_CEC_UICMD_RECORD_FUNCTION             = 0x62,
    HI_UNF_CEC_UICMD_PAUSE_RECORD_FUNCTION       = 0x63,
    HI_UNF_CEC_UICMD_STOP_FUNCTION               = 0x64,
    HI_UNF_CEC_UICMD_MUTE_FUNCTION               = 0x65,
    HI_UNF_CEC_UICMD_RESTORE_VOLUME_FUNCTION     = 0x66,
    HI_UNF_CEC_UICMD_TUNE_FUNCTION               = 0x67,
    HI_UNF_CEC_UICMD_SELECT_MEDIA_FUNCTION       = 0x68,
    HI_UNF_CEC_UICMD_SELECT_AV_INPUT_FUNCTION    = 0x69,
    HI_UNF_CEC_UICMD_SELECT_AUDIO_INPUT_FUNCTION = 0x6A,
    HI_UNF_CEC_UICMD_POWER_TOGGLE_FUNCTION       = 0x6B,
    HI_UNF_CEC_UICMD_POWER_OFF_FUNCTION          = 0x6C,
    HI_UNF_CEC_UICMD_POWER_ON_FUNCTION           = 0x6D,
    HI_UNF_CEC_UICMD_F1_BLUE                     = 0x71,
    HI_UNF_CEC_UICMD_F2_RED                      = 0x72,
    HI_UNF_CEC_UICMD_F3_GREEN                    = 0x73,
    HI_UNF_CEC_UICMD_F4_YELLOW                   = 0x74,
    HI_UNF_CEC_UICMD_F5                          = 0x75,
    HI_UNF_CEC_UICMD_DATA                        = 0x76
}HI_UNF_CEC_UICMD_E;

/**HDMI CEC operand command,please reference  HDMI specification 1.4a*/
/**CNcomment: HDMI CEC \B2\D9\D7\F7ָ\C1\C7\EB\B2ο\BCHDMI 1.4aЭ\D2\E9 */
/**member stUIOpcode:
\ member stUIOpcode not support when "CEC OPERAND FORCE RAWDATA" set Y on make menuconfig options
\ or just support when u8Opcode is <User Control Pressed>
\ CNcomment:
\ \B5\B1make menuconfig\B2\CE\CA\FDѡ\D4\F1\C1\CBCEC OPERAND FORCE RAWDATAʱ, \B3\C9ԱstUIOpcode\B2\BB\BF\C9\D3\C3;
\ \B5\B1û\D3\D0ѡ\D4\F1\B4˺\EAʱ\A3\ACu8OpcodeΪ<User Control Pressed>ʱֻ\C4\DCʹ\D3ó\C9ԱstUIOpcode
*/
typedef union hiUNF_CEC_Operand_t
{
    HI_UNF_CEC_RAWDATA_S               stRawData;   /**<CEC raw date*//**<CNcomment:CEC ԭʼ\C3\FC\C1\EE */
    HI_UNF_CEC_UICMD_E                 stUIOpcode;  /**<CEC user interface command*//**<CNcomment:CEC\D3û\A7\D7Զ\A8\D2\E5\B2\D9\D7\F7 */
}HI_UNF_CEC_Operand_t;

/**HDMI CEC struct command*/
/**CNcomment: HDMI CEC \C3\FC\C1\EE\BDṹ */
typedef struct hiUNF_HDMI_CEC_CMD_S
{
    HI_UNF_CEC_LOGICALADD_S  enSrcAdd;     /**<logical address of source *//**<CNcomment:Դ\B6\CB\C9豸\B5\D8ַ */
    HI_UNF_CEC_LOGICALADD_S  enDstAdd;     /**<logical address of destination*//**<CNcomment:Ŀ\B1\EA\C9豸\B5\D8ַ */
    HI_U8                    u8Opcode;     /**<opration code*//**<CNcomment:\B2\D9\D7\F7\C2\EB*/
    HI_UNF_CEC_Operand_t     unOperand;    /**<operand*//**<CNcomment:\B2\D9\D7\F7\CA\FD*/
}HI_UNF_HDMI_CEC_CMD_S;

/**HDMI CEC status struct*/
/**CNcomment: HDMI CEC ״̬\BDṹ */
typedef struct hiUNF_HDMI_CEC_STATUS_S
{
    HI_BOOL bEnable;                                 /**<the flag of CEC work,HI_TRUE:CEC work enable,HI_FALSE:CEC no work ,other parameter no effect*/ /**<CNcomment:CEC \D5\FD\B3\A3\B9\A4\D7\F7\B1\EA\BC\C7λ\A3\AC\C8\E7\B9\FBΪHI_TRUE,CEC\BF\C9\D2\D4\D5\FD\B3\A3\B9\A4\D7\F7\A3\AC\C8\E7\B9\FBΪHI_FASLE,CEC\B5\C4\C6\E4\CB\FB\B2\CE\CA\FD\CE\DEЧ\A3\AC\B2\A2\C7Ҳ\BB\C4ܹ\A4\D7\F7 */
    HI_U8   u8PhysicalAddr[4];                       /**<CEC physics address*/ /**<CNcomment:CEC \CE\EF\C0\ED\B5\D8ַ */
    HI_U8   u8LogicalAddr;                           /**<CEC logic address,defualt 0x03*//**<CNcomment:CEC \C2߼\AD\B5\D8ַ\A3\ACĬ\C8\CFΪ\A3\BA0x03. */
    HI_U8   u8Network[HI_UNF_CEC_LOGICALADD_BUTT];   /**<CEC network struct ,1:the device can response CEC command*/ /**<CNcomment:CEC \B9\B9\BD\A8\B5\C4\CD\F8·\BDṹ\A3\ACΪ1\B1\EDʾ\B8\C3\C9豸\C4ܹ\BB\CF\ECӦCEC\C3\FC\C1\EE */
}HI_UNF_HDMI_CEC_STATUS_S;

/**HDMI CEC Regcallback param struct */
/**CNcomment: HDMI CEC \BBص\F7\BA\AF\CA\FD\B2\CE\CA\FD\BDṹ */
typedef HI_VOID (*HI_UNF_HDMI_CECCALLBACK)(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_CEC_CMD_S *pstCECCmd, HI_VOID *pData);


/**HDMI Callback Struct*/
/**CNcomment: HDMI\BBص\F7\BDṹ */
typedef struct hiUNF_HDMI_CECCALLBACK_FUNC_S
{
    HI_UNF_HDMI_CECCALLBACK pfnCECCallBack;       /**<callback function pointer*//**<CNcomment:\BBص\F7\BA\AF\CA\FDָ\D5\EB*/
    HI_VOID                *pPrivateData;         /**<callback funtion param*//**<CNcomment:\BBص\F7\BA\AF\CA\FD\B2\CE\CA\FD*/
 }HI_UNF_HDMI_CECCALLBACK_EXT_S;



/**HDMI HDCP key struct*/
/**CNcomment: HDMI HDCP \C3\DCԿ\BDṹ */
typedef struct hiUNF_HDMI_LOAD_KEY_S
{
    HI_U8 *pu8InputEncryptedKey;            /**<Encrypted key pointer *//**<CNcomment:\BC\D3\C3ܵ\C4\C3\DCԿ\CA\FD\D7\E9ͷ\B5\D8ַ */
    HI_U32 u32KeyLength;                    /**<Encrypted key length*//**<CNcomment:\BC\D3\C3ܵ\C4\C3\DCԿ\B3\A4\B6\C8 */
}HI_UNF_HDMI_LOAD_KEY_S;

/**HDMI HDCP SRM(system renewability messages) struct*/
/**CNcomment: HDMI HDCP SRM(ʧЧ\C1б\ED)\BDṹ */
typedef struct hiUNF_HDMI_SRM_S
{
    HI_U8 *pu8SrmData;              /**<SRM raw data *//**<CNcomment:SRM ԭʼ\CA\FD\BE\DD\CA\FD\D7\E9ͷ\B5\D8ַ */
    HI_U32 u32SrmLen;               /**<Length of SRM *//**<CNcomment:ԭʼ\CA\FD\BEݳ\A4\B6ȣ\AC\B5\A5λΪ\D7ֽ\DA */
} HI_UNF_HDMI_SRM_S;


/**< HDCP-capability struct *//**<CNcomment:HDCP \C4\DC\C1\A6\BDṹ\CC\E5 */
typedef struct{
    HI_BOOL        bHdcp14Support;  /**<sink support HDCP1.4 *//**<CNcomment:sink֧\B3\D6HDCP1.4 */
    HI_BOOL        bHdcp22Support;  /**<sink support HDCP2.2 *//**<CNcomment:sink֧\B3\D6HDCP2.2 */
}HI_UNF_HDMI_HDCP_CAP_S;

/**HDMI HDCP eanble parameter*/
/**CNcomment: HDMI HDCP ʹ\C4ܲ\CE\CA\FD */
typedef struct hiUNF_HDMI_HDCP_PARAM_S{
    HI_BOOL                 bHdcpEnable;    /**<set HI_TRUE to enable HDCP,set HI_FALSE to disable HDCP. *//**<CNcomment:\C9\E8\D6\C3HI_TRUEʹ\C4\DCHDCP;\C9\E8\D6\C3HI_FALSE\B9رչر\D5HDCP*/
    HI_UNF_HDMI_HDCP_MODE_E enHdcpMode;     /**<HDCP mode of authentication,suggest that according to HDCP-capability. *//**<CNcomment:HDCP\C8\CF֤ģʽ\A3\AC\BD\A8\D2\E9\BB\F1ȡsink\C4\DC\C1\A6֮\BA\F3\B8\F9\BE\DD\C4\DC\C1\A6\C9\E8\D6\C3*/

}HI_UNF_HDMI_HDCP_PARAM_S;

/**HDMI HDCP error code*/
/**CNcomment: HDMI HDCP\B4\ED\CE\F3\C2\EB*/
typedef enum hiUNF_HDMI_HDCP_ERR_E
{
    HI_UNF_HDMI_HDCP_ERR_UNDO = 0x00,           /**< undo hdcp. *//**<CNcomment:δ\BD\F8\D0\D0HDCP\C8\CF֤*/
    HI_UNF_HDMI_HDCP_ERR_NONE,                  /**< no error. *//**<CNcomment:û\D3з\A2\C9\FAHDCP\C8\CF֤\B4\ED\CE\F3*/
    HI_UNF_HDMI_HDCP_ERR_UNHPD,                 /**< eanble HDCP when HPD is low. *//**<CNcomment:HPDΪ\B5\CDʱʹ\C4\DC\C8\CF֤*/
    HI_UNF_HDMI_HDCP_ERR_NO_TIMMING,            /**< no timming.Enable HDCP before HDMI start. *//**<CNcomment:\CE\DEʱ\D0\F2\A3\AC\D4\DAHDMI\CE\DE\CA\D3Ƶ\CA\E4\B3\F6ʱʹ\C4\DCʹ\C4\DCHDCP(HDMI δ\C6\F4\B6\AF)*/
    HI_UNF_HDMI_HDCP_ERR_LOADKEY_FAIL,          /**< no loadkey.Only for HDCP1.4 *//**<CNcomment:δ\BC\D3\D4\D8HDCP1.4 key*/
    HI_UNF_HDMI_HDCP_ERR_ON_REVOCATION_LIST,    /**< recieve ID/BKSV list on revocation list.*//**<CNcomment:\BD\D3\CA\D5\C9豸(\B0\FC\BA\AC\CF\C2\D3\CE\C9豸)\D4\DADCPʧЧ\C1б\ED\BA\DA\C3\FB\B5\A5\D6\D0*/
    HI_UNF_HDMI_HDCP_ERR_RECEIVER_FAIL,         /**< receiver respond error.*//**<CNcomment:\BD\D3\CA\D5\C9豸\CF\ECӦ\B4\ED\CE\F3\D0\C5Ϣ*/
    HI_UNF_HDMI_HDCP_ERR_MAXDEV_EXCEEDED,       /**< more than 127 downstream devices,  or the capacity of the KSV Fifo, are attached.*//**<CNcomment:\CD\D8\C6\CB\D6\D0\C9豸\CA\FD\C1\BF\B3\AC\B9\FD\D7\EE\B4\F3ֵ127\A3\AC\BB\F2\D5ߴ\E6\D4\DA\C9豸KSV Fifo\B2\BB\D7\E3\C7\E9\BF\F6*/
    HI_UNF_HDMI_HDCP_ERR_MAXCASCADE_EXCEEDED,   /**< more than seven levels of video repeater have been cascaded together*//**<CNcomment:\CD\D8\C6\CB\D6г\AC\B9\FD7\BC\B6\C9豸\B2\E3\CA\FD*/
    HI_UNF_HDMI_HDCP_ERR_REPEATER_FAIL,         /**< repeater respond error.*//**<CNcomment:repeater\C9豸\CF\ECӦ\B4\ED\CE\F3\D0\C5Ϣ*/

}HI_UNF_HDMI_HDCP_ERR_E;

/**HDMI HDCP status */
/**CNcomment: HDMI HDCP״̬*/
typedef struct hiUNF_HDCP_STATUS_S{
    HI_UNF_HDMI_HDCP_VERSION_E      enHdcpVersion;  /**< HDCP current version.*//**<CNcomment:HDCP\B5\B1ǰ\B0汾*/
    HI_BOOL                         bHdcpEnable;    /**< HDCP enable status.*//**<CNcomment:HDCPʹ\C4\DC״̬*/
    HI_UNF_HDMI_HDCP_ERR_E          enHdcpErrCode;  /**< HDCP error code.*//**<CNcomment:HDCP \B4\ED\CE\F3\C2\EB*/
}HI_UNF_HDCP_STATUS_S;


/**HDMI Delay struct*/
/**CNcomment: HDMI \D1\D3ʱ\BDṹ */
typedef struct hiUNF_HDMI_DELAY_S
{
    HI_U32  u32MuteDelay;           /**<delay for avmute *//**<CNcomment:avmute\B5\C4\D1\D3ʱ */
    HI_U32  u32FmtDelay;            /**<delay for setformat *//**<CNcomment:\C9\E8\D6\C3\D6\C6ʽ\B5\C4\D1\D3ʱ */
    HI_BOOL bForceFmtDelay;         /**<force setformat delay mode *//**<CNcomment:\C7л\BB\D6\C6ʽǿ\D6\C6\D1\D3ʱģʽ */
    HI_BOOL bForceMuteDelay;        /**<force avmute delay mode *//**<CNcomment:muteǿ\D6\C6\D1\D3ʱģʽ */
}HI_UNF_HDMI_DELAY_S;

/**HDMI Resume start flag*/
/**CNcomment: ϵͳ\BB\BD\D0\D1ʱHDMI\C7\FD\B6\AF\CAǷ\F1\D6\F7\B6\AF\B4\F2\BF\AA\CA\E4\B3\F6 */
typedef enum hiUNF_HDMI_RESUME_START_E
{
    HI_UNF_HDMI_RESUME_AND_START = 0,   /**<HDMI starts when the system is resumed*//**<CNcomment:ϵͳResumeʱHDMI\C7\FD\B6\AF\D6\F7\B6\AFstart*/
    HI_UNF_HDMI_RESUME_NOT_START        /**<HDMI not start when the system is resumed*//**<CNcomment:ϵͳResumeʱHDMI\C7\FD\B6\AF\B2\BB\D6\F7\B6\AFstart*/
} HI_UNF_HDMI_RESUME_START_E;

/**HDMI advanced attribute struct*/
/**CNcomment: HDMI\B8߼\B6\CA\F4\D0Խṹ */
typedef struct hiUNF_HDMI_ADVANCED_ATTR_S
{
    HI_UNF_HDMI_RESUME_START_E enResumeStart;
}HI_UNF_HDMI_ADVANCED_ATTR_S;


/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      HDMI */
/** @{ */  /** <!-- [HDMI] */

/**
\brief the whole initialization of the hdmi. CNcomment:HDMI\BDӿ\DA\C7\FD\B6\AF\C8\ED\BC\FE\B3\F5ʼ\BB\AF CNend
\attention  this func should be called before vo_init and after disp_init. CNcomment:\B1\D8\D0\EB\D4\DADISP\C7\FD\B6\AFSetup֮\BA\F3\BA\CDVO\C7\FD\B6\AFSetup֮ǰ\B4\F2\BF\AA CNend
\param CNcomment:\CE\DE CNend
\retval HI_SUCCESS  success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_Init(HI_VOID);


/**
\brief deinit the hdmi. CNcomment:HDMI\BDӿ\DAȥ\B3\F5ʼ\BB\AF CNend
\attention  this must be called after vo exited and before disp  exited . CNcomment:\B1\D8\D0\EB\D4\DAVO\C7\FD\B6\AFExit֮\BA\F3\BA\CDDISP\C7\FD\B6\AFExit֮ǰ\B4\F2\BF\AA CNend
\param CNcomment:\CE\DE CNend
\retval HI_SUCCESS      success.CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_DeInit(HI_VOID);


/**
\brief create hdmi device. CNcomment:\B4\B4\BD\A8HDMI\C9豸 CNend
\attention \n
\param[in] enHdmi  hdmi device id. CNcomment:Ҫ\B4򿪵\C4HDMI\C9豸 CNend
\param[in] pstOpenPara  When get GetSinkCapability failed,defalut set sink device to DVI/HDMI mode.CNcomment:δ\BB\F1ȡ\B5\BD\B6Զ\CB\C4\DC\C1\A6\BC\AFʱ\A3\ACĬ\C8ϰѶԶ˵\B1\B3\C9(DVI/HDMI)\C9豸 CNend
\retval HI_SUCCESS     success.  CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_Open(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_OPEN_PARA_S *pstOpenPara);

/**
\brief close the handler created by  HI_UNF_HDMI_Open. CNcomment:\CF\FA\BB\D9\D3\C9HI_UNF_HDMI_Open\B4\B4\BD\A8\B5ľ\E4\B1\FA CNend
\attention \n
\param[in] enHdmi  hdmi device id. CNcomment:HDMI\C9豸ID CNend
\retval HI_SUCCESS     success.  CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_Close(HI_UNF_HDMI_ID_E enHdmi);

/**
\brief get current hdmi status. CNcomment:\BB\F1ȡhdmi\B5\B1ǰ\B5\C4״̬ CNend
\attention \n
\param[in] enHdmi  hdmi device id. CNcomment:HDMI\C9豸ID CNend
\param[out] pHdmiStatus hdmi cuttent status. CNcomment:HDMI\B5\B1ǰ״̬ CNend
\retval HI_SUCCESS     success.  CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_GetStatus(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_STATUS_S *pHdmiStatus);

/**
\brief to get the capability of sink connect to stbbox. CNcomment:\B2\E9ѯ\BB\F1ȡHDMI Sink\C9豸\B5\C4\C4\DC\C1\A6\BC\AF CNend
\attention \n
\param[in] enHdmi   hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[out] pCapability  the capability of the sink .CNcomment:SINK\C4\DC\C1\A6\BC\AF CNend
\retval HI_SUCCESS       success.  CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi. CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see ::HI_UNF_EDID_BASE_INFO_S\n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_GetSinkCapability(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_EDID_BASE_INFO_S *pCapability);

/**
\brief set the attr of given hdmi interface. CNcomment:\C9\E8\D6\C3HDMI\BDӿ\DA\CA\F4\D0ԡ\A3 CNend
\attention the setting will take effect after HI_UNF_HDMI_Start is called.Suggest that HI_UNF_HDMI_Stop before change enDeepColorMode to reduce noisy.
\param[in] enHdmi      hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[in] pstAttr     the attr of given hdmi interface.CNcomment:HDMI\BDӿ\DA\CA\F4\D0\D4 CNend
\retval HI_SUCCESS     success.  CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see ::HI_UNF_HDMI_ATTR_S\n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_SetAttr(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_ATTR_S *pstAttr);


/**
\brief get the current attr of the give hdmi interface. CNcomment:\B2\E9ѯHDMI\BDӿڵ\B1ǰ\CA\F4\D0\D4 CNend
\attention \n
\param[in] enHdmi hdmi device id.CNcomment: HDMI\C9豸ID CNend
\param[out] pstAttr     the attr of given hdmi interface. CNcomment:HDMI\BDӿ\DA\CA\F4\D0\D4 CNend
\retval HI_SUCCESS      success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see HI_UNF_HDMI_ATTR_S\n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_GetAttr(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_ATTR_S *pstAttr);


/**
\brief get the cec working status. CNcomment:\BB\F1ȡCEC״̬ CNend
\attention  user can get the cec working status through this func. CNcomment:\BFͻ\A7\BF\C9\D2\D4ͨ\B9\FD\B8ýӿڻ\F1ȡCEC\B9\A4\D7\F7״̬\n CNend
\param[in] enHdmi       hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[in] pStatus     get cec working status. CNcomment:CEC ״̬ CNend
\retval HI_SUCCESS     success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see ::HI_UNF_HDMI_CEC_CMD_S\n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_CECStatus(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_CEC_STATUS_S  *pStatus);


/**
\brief send the cec data. CNcomment:\B7\A2\CB\CDCEC \C3\FC\C1\EE CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI\C9豸ID CNend
\param[in] pCECCmd      the cec cmd data.CNcomment:Cec Command \C4\DA\C8\DD CNend
\retval HI_SUCCESS     success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see ::HI_UNF_HDMI_CEC_CMD_S\n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_SetCECCommand(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_CEC_CMD_S  *pCECCmd);


/**
\brief get the cec data received. CNcomment:\BD\D3\CAյ\C4CEC \C3\FC\C1\EE CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI\C9豸ID CNend
\param[in] pCECCmd    the cec cmd data. CNcomment:Cec Command \C4\DA\C8\DD CNend
\param[in] timeout    timeout for getting cec cmd, unit: 10ms;
\retval HI_SUCCESS      success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see ::HI_UNF_HDMI_CEC_CMD_S\n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_GetCECCommand(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_CEC_CMD_S  *pCECCmd, HI_U32 timeout);

/**
\brief register CEC callback function. CNcomment:ע\B2\E1\BB\F1ȡCEC\BBص\F7\BA\AF\CA\FD CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI\C9豸ID CNend
\param[in] pCECCallback    the cec callback handle. CNcomment:\BBص\F7\BA\AF\CA\FD\BE\E4\B1\FA CNend
\retval HI_SUCCESS      success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see ::HI_UNF_HDMI_CECCALLBACK,HI_UNF_HDMI_RegCECCallBackFuncExt\n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_RegCECCallBackFunc(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_CECCALLBACK pCECCallback);

/**
\brief unregister CEC callback function. CNcomment:\B7\B4ע\B2\E1\BB\F1ȡCEC\BBص\F7\BA\AF\CA\FD CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI\C9豸ID CNend
\param[in] pCECCallback  the cec callback handle. CNcomment:\BBص\F7\BA\AF\CA\FD\BE\E4\B1\FA CNend
\retval HI_SUCCESS      success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\NOTE:: You should un-register when finished using the CEC_CALLBACK function before HI_UNF_HDMI_DeInit.Associate with HI_UNF_HDMI_RegCECCallBackFunc.CNcomment:\CD˳\F6ǰ\C7\EBע\CF\FA\BBص\F7\BA\AF\CA\FD CNend
\see ::HI_UNF_HDMI_CECCALLBACK,HI_UNF_HDMI_UnRegCECCallBackFuncExt\n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_UnRegCECCallBackFunc(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_CECCALLBACK pCECCallback);


/**
\brief register CEC callback function, only use with HI_UNF_HDMI_RegCECCallbackFuncExt. CNcomment:ע\B2\E1\BB\F1ȡCEC\BBص\F7\BA\AF\CA\FD\A3\AC\BD\F6\D3\EB HI_UNF_HDMI_UnRegCECCallBackFunc\C5\E4\CC\D7ʹ\D3\C3 CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI\C9豸ID CNend
\param[in] pstCallBackFunc    the cec callback handle. CNcomment:\BBص\F7\BA\AF\CA\FD\BE\E4\B1\FA CNend
\retval HI_SUCCESS      success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\NOTE:: You can use the interface deliver a private data pointer.But HI_UNF_HDMI_RegCECCallBackFunc can't support.You can select one of them.CNcomment:\B1\BE\BDӿ\DA֧\B3ִ\AB\C8\EB˽\D3\D0\CA\FD\BE\DDָ\D5룬\B5\AB HI_UNF_HDMI_RegCECCallBackFunc\B2\BB֧\B3\D6,\C7\EB\B8\F9\BE\DD\D0\E8Ҫѡ\D4\F1\C6\E4\D6\D0֮һʹ\D3ü\B4\BFɡ\A3 CNend
\see ::HI_UNF_HDMI_CECCALLBACK_EXT_S\n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_RegCECCallBackFuncExt(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_CECCALLBACK_EXT_S *pstCallBackExt);

/**
\brief unregister CEC callback function. CNcomment:\B7\B4ע\B2\E1\BB\F1ȡCEC\BBص\F7\BA\AF\CA\FD CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI\C9豸ID CNend
\param[in] pstCallBackFunc  the cec callback handle. CNcomment:\BBص\F7\BA\AF\CA\FD\BE\E4\B1\FA CNend
\retval HI_SUCCESS      success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\NOTE:: You should un-register when finished using the CEC_CALLBACK function before HI_UNF_HDMI_DeInit.Associate with HI_UNF_HDMI_RegCECCallBackFuncExt.CNcomment:\CD˳\F6ǰ\C7\EBע\CF\FA\BBص\F7\BA\AF\CA\FD CNend
\see ::HI_UNF_HDMI_CECCALLBACK_EXT_S\n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_UnRegCECCallBackFuncExt(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_CECCALLBACK_EXT_S *pstCallBackExt);


/**
\brief enable the cec func. CNcomment:CEC ʹ\C4ܴ\F2\BF\AA CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI\C9豸ID CNend
\retval HI_SUCCESS     success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_CEC_Enable(HI_UNF_HDMI_ID_E enHdmi);

/**
\brief disable the cec func. CNcomment:CEC ʹ\C4ܹر\D5 CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI\C9豸ID CNend
\retval HI_SUCCESS      success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_CEC_Disable(HI_UNF_HDMI_ID_E enHdmi);

/**
\brief  set and send infoframe. CNcomment:\C9\E8\D6ò\A2\B7\A2\CB\CDInfoFrame CNend
\attention \n
\param[in] enHdmi       hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[in] pstInfoFrame the inforframe content.CNcomment:InfoFrame\C4\DA\C8\DD CNend
\retval HI_SUCCESS      success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_SetInfoFrame(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_INFOFRAME_S *pstInfoFrame);

/**
\brief get the infoframe infor. CNcomment:\BB\F1ȡ\D5\FD\D4ڷ\A2\CB͵\C4InfoFrame\B5\C4\D0\C5Ϣ CNend
\attention \n
\param[in] enHdmi       hdmi device id. CNcomment:HDMI\C9豸ID CNend
\param[in] enInfoFrameType the info frame type such as avi or audio or gcp etc. CNcomment:InfoFrame\C0\E0\D0\CD CNend
\param[out] pstInfoFrame   the inforframe content.CNcomment:InfoFrame\C4\DA\C8\DD CNend
\retval HI_SUCCESS      success.CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_GetInfoFrame(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_INFOFRAME_TYPE_E enInfoFrameType, HI_UNF_HDMI_INFOFRAME_S *pstInfoFrame);



/**
\brief  start the hdmi works. CNcomment:HDMI\BF\AAʼ CNend
\attention \n
this should be called after HI_UNF_HDMI_SetAttr.
CNcomment:\C6\F4\B6\AFHDMI\BDӿڡ\A3һ\B0\E3\D4\DAHI_UNF_HDMI_SetAttr֮\BA\F3\B5\F7\D3\C3 CNend
\param[in] enHdmi   hdmi device id.CNcomment:HDMI\C9豸ID CNend
\retval HI_SUCCESS     success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_Start(HI_UNF_HDMI_ID_E enHdmi);

/**
\brief stop  the hdmi. CNcomment:hdmiֹͣ CNend
\attention \n
this func should be called  when hdmi plug out.
CNcomment:\B5\B1HDMI\CF߱\BB\B0γ\FD\BA\F3\A3\ACHDMI\BBص\F7\BA\AF\CA\FDӦ\B8õ\F7\D3øú\AF\CA\FD\A1\A3 CNend
\param[in] enHdmi  hdmi device id. CNcomment:HDMI\C9豸ID CNend
\retval HI_SUCCESS     success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_Stop(HI_UNF_HDMI_ID_E enHdmi);

/**
\brief set the deep color mode. CNcomment:\C9\E8\D6\C3HDMI DeepColorģʽ CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI\C9豸ID CNend
\param[in] enDeepColor deep color mode,please refer to the HI_UNF_HDMI_DEEP_COLOR_E definiton.CNcomment:DeepColorģʽ\A3\AC\C7\EB\B2ο\BC::HI_UNF_HDMI_DEEP_COLOR_E  CNend
\retval HI_SUCCESS     success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_SetDeepColor(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_DEEP_COLOR_E enDeepColor);

/**
\brief switch the xvycc on or off. CNcomment:\C9\E8\D6\C3HDMI xvYCC ģʽ CNend
\attention \n
\param[in] enHdmi   hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[in] bEnalbe   whether to enable xvycc mode or not .CNcomment:\CAǷ\F1ʹ\C4\DCxvYCCģʽ CNend
\retval HI_SUCCESS    success.  CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_SetxvYCCMode(HI_UNF_HDMI_ID_E enHdmi, HI_BOOL bEnalbe);

/**
\brief switch the mute of av  on or off. CNcomment:\C9\E8\D6\C3HDMI AV mute ģʽ CNend
\attention \n
\param[in] enHdmi   hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[in] bAvMute   whether to mute the av.CNcomment:\CAǷ\F1mute AV CNend
\retval HI_SUCCESS     success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_SetAVMute(HI_UNF_HDMI_ID_E enHdmi, HI_BOOL bAvMute);

/**
\brief get the edid information forcelly. CNcomment:ǿ\D6ƻ\F1ȡEDIDԭʼ\CA\FD\BE\DD,\B8ýӿ\DAΪ\CCض\A8ƽ̨\D0\E8Ҫ\BB\F1ȡԭʼEDID\B5Ľӿ\DA CNend
\attention \n
\param[in] enHdmi   hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[out] *u8Edid  the buffer allocated externally, buffer size must be 512. CNcomment:\BB\F1ȡԭʼEDID\CA\FD\BE\DDbuffer\A1\A3EDID\B0汾\B2\BBͬ\A3\AC\B6\C1\B3\F6\C0\B4\B5\C4\CA\FD\BEݲ\BBͬ\A3\ACȡ\C9\CF\CF\DEbuffer \B4\F3СΪ512,\D3û\A7\D0\E8\D7Լ\BA\B7\D6\C5\E4\BA\C3; CNend
\param[in] u32EdidBufSize  size of the Edid buffer. CNcomment:EDID\CA\FD\BE\DDbuffer\B4\F3С CNend
\param[out] *u32EdidLength  the data lenth of  original edid. CNcomment:\BB\F1ȡԭʼEDID\CA\FD\BEݳ\A4\B6\C8 CNend
\retval HI_SUCCESS   success.   CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_Force_GetEDID(HI_UNF_HDMI_ID_E enHdmi, HI_U8 *u8Edid, HI_U32 u32EdidBufSize, HI_U32 *u32EdidLength);


/**
\brief register callback function. CNcomment:ע\B2\E1\BBص\F7\BA\AF\CA\FD CNend
\attention \n
this func should be called before HI_UNF_HDMI_Open and after HI_UNF_HDMI_Init
because HI_UNF_HDMI_Open will trigger hotplug event.
And this function can only register one function
If call this func two times,then the 2nd callback function will cover 1st one.
CNcomment:\BD\A8\D2\E9\D4\DAHI_UNF_HDMI_Init֮\BA\F3\BA\CDHI_UNF_HDMI_Open֮ǰ\B5\F7\D3\C3 \n
\D2\F2ΪOpenʱ\C8\E7\B9\FB\C1\AC\D7Ž\D3\CAն\CB\C9豸\C9ϻᴥ\B7\A2һ\B4\CEhotplug\CF\FBϢ \n
\B8ú\AF\CA\FDֻ\C4\DCע\B2\E1һ\B8\F6\BBص\F7\BA\AF\CA\FD\A3\AC\B5ڶ\FE\B4\CEע\B2\E1\B5Ļص\F7\BA\AF\CA\FD\BBḲ\B8\C7ǰ\C3\E6\B5Ļص\F7\BA\AF\CA\FD CNend
\param CNcomment:\CE\DE CNend
\param[in] enHdmi   hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[in] *HI_UNF_HDMI_CALLBACK_FUNC_S  callback function CNcomment:\BBص\F7\BA\AF\CA\FD CNend
\retval HI_SUCCESS   success.   CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_RegCallbackFunc(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_CALLBACK_FUNC_S *pstCallbackFunc);


/**
\brief unregister CallbackFunc. CNcomment:ע\CF\FA\BBص\F7\BA\AF\CA\FD CNend
\attention \n
this func should be called before HI_UNF_HDMI_DeInit and after HI_UNF_HDMI_Close
CNcomment:\BD\A8\D2\E9\D4\DAHI_UNF_HDMI_Close֮\BA\F3\BA\CDHI_UNF_HDMI_DeInit֮ǰ\B5\F7\D3\C3 CNend
\param[in] enHdmi   hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[in] *HI_UNF_HDMI_CALLBACK_FUNC_S  callback function CNcomment:\BBص\F7\BA\AF\CA\FD CNend
\retval HI_SUCCESS   success.   CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_UnRegCallbackFunc(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_CALLBACK_FUNC_S *pstCallbackFunc);

/**
\brief Load HDCP key. CNcomment:\B5\BC\C8\EBhdcpkey CNend
\attention \n
\param[in] enHdmi   hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[in] *pstLoadKey  key struct length and point CNcomment:key \B5Ľṹ \B3\A4\B6Ⱥ\CDָ\D5\EB CNend
\retval HI_SUCCESS   success.   CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_LoadHDCPKey(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_LOAD_KEY_S *pstLoadKey);

/**
\brief Set SRM, it is called by user, it can be call more time,only remain the last one when set success.Ncomment:\B5\BC\C8\EBSRM\CA\FD\BE\DD CNend
\param[in]  enHdmi  hdmi channel id. CNcomment:HDMI\C9豸ID CNend
\param[in]  pstSrm SRM raw dataCNcomment:SRM\BDṹ ָ\D5\EB CNend
\retval HI_SUCCESS   success/HI_FAILURE fail.  CNcomment:\B3ɹ\A6/ʧ\B0\DC CNend
*/
HI_S32 HI_UNF_HDMI_SetSrm(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_SRM_S *pstSrm);

/**
\brief to get the HDCP-capability of sink connect to stbbox. CNcomment:\BB\F1ȡHDMI Sink\C9豸\B5\C4HDCP\C4\DC\C1\A6 CNend
\attention in HI_UNF_HDMI_GetSinkCapability,HI_UNF_EDID_BASE_INFO_S's stHDCPSupport is triggered by HotPlug,some Sink get HDCP-capability fail when HotPlug.Base on these,it is suggested that use HI_UNF_HDMI_GetHdcpCapability force to get HDCP-capability from sink.When retval is HI_FAILURE,it is suggested that use HI_UNF_HDMI_GetHdcpCapability to get more times until retval is HI_SUCCESS.
\CNcomment:ע\D2⣬HI_UNF_EDID_BASE_INFO_S\B5\C4stHDCPSupportֻ\D4\DAHotPlug\B5\BD\C0\B4ʱ\BB\F1ȡsink\C4\DC\C1\A6\A3\AC\B2\BF\B7ֵ\E7\CAӿ\C9\C4\DCδ׼\B1\B8\BAö\F8\BB\F1ȡʧ\B0ܡ\A3ǿ\C1ҽ\A8\D2\E9ʹ\D3\C3HI_UNF_HDMI_GetHdcpCapability\BB\F1ȡsink\B5\C4HDCP\C4\DC\C1\A6\A1\A3\C8\F4\B7\B5\BB\D8ֵΪHI_FAILURE,\BD\A8\D2\E9\BB\F1ȡ\B6\E0\B4Σ\ACֱ\B5\BD\B7\B5\BB\D8ֵHI_SUCCESS\A1\A3 CNend
\param[in] enHdmi   hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[out] pstHdcpCap  the HDCP capability of the sink .CNcomment:SINK\B5\C4HDCP\C4\DC\C1\A6 CNend
\retval HI_SUCCESS   success/HI_FAILURE fail.  CNcomment:\B3ɹ\A6/ʧ\B0\DC CNend
*/
HI_S32 HI_UNF_HDMI_GetHdcpCapability(HI_UNF_HDMI_ID_E enHdmi,HI_UNF_HDMI_HDCP_CAP_S *pstHdcpCap);

/**
\brief to enable HDCP authentication dynamically after HI_UNF_HDMI_Start. CNcomment:\B6\AF̬ʹ\C4\DCHDCP\C8\CF֤ CNend
\attention the interface must call after HI_UNF_HDMI_Start.And ,it is suggested that select enHdcpMode according to sink's HDCP-capability.
\CNcomment:ע\D2⣬\B8ýӿڱ\D8\D0\EB\D4\DAHI_UNF_HDMI_Start֮\BA\F3\B5\F7\D3á\A3\BD\A8\D2\E9\B8\F9\BE\DDsink\B5\C4HDCP\C4\DC\C1\A6ѡ\D4\F1\B6\D4Ӧģʽ\A1\A3 CNend
\param[in] enHdmi   hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[in] pstParm  hdcp parameter when enable.CNcomment:HDCPʹ\C4ܲ\CE\CA\FD CNend
\retval HI_SUCCESS   success/HI_FAILURE fail.  CNcomment:\B3ɹ\A6/ʧ\B0\DC CNend
*/
HI_S32 HI_UNF_HDMI_HdcpEnable(HI_UNF_HDMI_ID_E enHdmi,HI_UNF_HDMI_HDCP_PARAM_S *pstParm);

/**
\brief to get HDCP status. CNcomment:\BB\F1ȡHDCP\C8\CF֤״̬ CNend
\attention suggest the interface call after getting HDCP event.CNcomment:\BD\A8\D2\E9\D4ڻ\F1ȡHDCP\CA¼\FE\BA\F3\B5\F7\D3\C3 CNend
\param[in] enHdmi   hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[in] pstStatus  hdcp status.CNcomment:HDCP\C8\CF֤״̬ CNend
\retval HI_SUCCESS   success/HI_FAILURE fail.  CNcomment:\B3ɹ\A6/ʧ\B0\DC CNend
*/
HI_S32 HI_UNF_HDMI_GetHdcpStatus(HI_UNF_HDMI_ID_E enHdmi,HI_UNF_HDCP_STATUS_S *pstStatus);


/**
\brief get the edid information forcelly. CNcomment:\B4\D3EEPROM\BB\F1ȡEDID\CA\FD\BE\DD CNend
\attention \n
Difference with two interface for get EDID
HI_UNF_HDMI_Force_GetEDID : Reread EDID from Sink,and write it to EEPROM
HI_UNF_HDMI_ReadEDID : read edid from EEPROM,not Real-time read from Sink
CNcomment:\C1\BD\B8\F6\BB\F1ȡEDID\B5Ľӿڲ\EE\B1\F0
HI_UNF_HDMI_Force_GetEDID \CA\C7\D6\D8\D0´ӽ\D3\CAն˶\C1ȡEdid\A3\AC\B2\A2д\B5\BDEEPROM
HI_UNF_HDMI_ReadEDID \CAǴ\D3EEPROM\B6\C1ȡEdid\A3\AC\B6\F8\B2\BB\CA\C7ʵʱ\B5Ľ\D3\CAն\CBEDID CNend
\param[out] *u8Edid  the buffer allocated externally, buffer size must be 512. CNcomment:\BB\F1ȡԭʼEDID\CA\FD\BE\DDbuffer\A1\A3EDID\B0汾\B2\BBͬ\A3\AC\B6\C1\B3\F6\C0\B4\B5\C4\CA\FD\BEݲ\BBͬ\A3\ACȡ\C9\CF\CF\DEbuffer \B4\F3СΪ512,\D3û\A7\D0\E8\D7Լ\BA\B7\D6\C5\E4\BA\C3; CNend
\param[in] u32EdidBufSize  size of the Edid buffer. CNcomment:EDID\CA\FD\BE\DDbuffer\B4\F3С CNend
\param[out] *u32EdidLength  the data lenth of  original edid. CNcomment:\BB\F1ȡԭʼEDID\CA\FD\BEݳ\A4\B6\C8 CNend
\retval HI_SUCCESS   success.   CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_ReadEDID(HI_U8 *u8Edid, HI_U32 u32EdidBufSize, HI_U32 *u32EdidLength);

/**
\brief Get HDMI runtime delay. CNcomment:\BB\F1ȡhdmi\D4\CB\D0\D0ʱ\D1\D3ʱ CNend
\attention \n
CNend
\param[in] *pstDelay  delay struct delay time and mode CNcomment:\D1\D3ʱ\BDṹ\CC\E5 \D1\D3ʱ\B5\C4ʱ\B3\A4\BA\CDģʽ CNend
\retval HI_SUCCESS   success.   CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_GetDelay(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_DELAY_S *pstDelay);

/**
\brief Set HDMI runtime delay. CNcomment:\C9\E8\D6\C3hdmi\D4\CB\D0\D0ʱ\D1\D3ʱ CNend
\attention \n
if not use this interface, then use hdmi inner delay
CNcomment:Ĭ\C8\CF\C7\E9\BF\F6\CFµ\F7\D3øýӿ\DAǰ\BB\E1ʹ\D3\C3\C4ڲ\BF\D1\D3ʱ,\B5\F7\D3ú\F3\B8\F9\BE\DDdelayģʽʹ\D3\C3\D1\D3ʱ CNend
\param[in] *pstDelay  delay struct delay time and mode CNcomment:\D1\D3ʱ\BDṹ\CC\E5 \D1\D3ʱ\B5\C4ʱ\B3\A4\BA\CDģʽ CNend
\retval HI_SUCCESS   success.   CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_SetDelay(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_DELAY_S *pstDelay);

/**
\brief set the advanced attr of given hdmi interface. CNcomment:\C9\E8\D6\C3HDMI\BDӿڵĸ߼\B6\CA\F4\D0ԡ\A3 CNend
\attention when the pstAdvancedAttr->enResumeStart is set to HI_UNF_HDMI_RESUME_NOT_START, resuming the system needs to call HI_UNF_HDMI_Start().
\param[in] enHdmi      hdmi device id.CNcomment:HDMI\C9豸ID CNend
\param[in] pstAdvancedAttr     the attr of given hdmi interface.CNcomment:HDMI\BDӿڸ߼\B6\CA\F4\D0\D4 CNend
\retval HI_SUCCESS     success.  CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see ::HI_UNF_HDMI_ADVANCED_ATTR_S\n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_SetAdvancedAttr(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_ADVANCED_ATTR_S *pstAdvancedAttr);

/**
\brief get the current advanced attr of the give hdmi interface. CNcomment:\B2\E9ѯHDMI\BDӿڵ\B1ǰ\B5ĸ߼\B6\CA\F4\D0\D4 CNend
\attention \n
\param[in] enHdmi hdmi device id.CNcomment: HDMI\C9豸ID CNend
\param[out] pstAdvancedAttr     the attr of given hdmi interface. CNcomment:HDMI\BDӿڸ߼\B6\CA\F4\D0\D4 CNend
\retval HI_SUCCESS      success. CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see HI_UNF_HDMI_ADVANCED_ATTR_S\n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_HDMI_GetAdvancedAttr(HI_UNF_HDMI_ID_E enHdmi, HI_UNF_HDMI_ADVANCED_ATTR_S *pstAdvancedAttr);

/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __HI_UNF_HDMI_H__ */

