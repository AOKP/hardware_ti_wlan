/*
 * This file is part of wl18xx
 *
 * Copyright (C) 2011 Texas Instruments. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#ifndef __WL18XX_ACX_H__
#define __WL18XX_ACX_H__

#include "../wlcore/wlcore.h"
#include "../wlcore/acx.h"

/* numbers of bits the length field takes (add 1 for the actual number) */
#define WL18XX_HOST_IF_LEN_SIZE_FIELD 15

struct wl18xx_acx_host_config_bitmap {
	struct acx_header header;

	__le32 host_cfg_bitmap;

	__le32 host_sdio_block_size;

	/* extra mem blocks per frame in TX. */
	__le32 extra_mem_blocks;

	/*
	 * number of bits of the length field in the first TX word
	 * (up to 15 - for using the entire 16 bits).
	 */
	__le32 length_field_size;

} __packed;

enum {
	CHECKSUM_OFFLOAD_DISABLED = 0,
	CHECKSUM_OFFLOAD_ENABLED  = 1,
	CHECKSUM_OFFLOAD_FAKE_RX  = 2,
	CHECKSUM_OFFLOAD_INVALID  = 0xFF
};

struct wl18xx_acx_checksum_state {
	struct acx_header header;

	 /* enum acx_checksum_state */
	u8 checksum_state;
	u8 pad[3];
} __packed;

struct wl18xx_acx_debug_stats {
	u32 debug1;
	u32 debug2;
	u32 debug3;
	u32 debug4;
	u32 debug5;
	u32 debug6;
} __packed;

struct wl18xx_acx_ring_stats {
	u32 tx_procs;
	u32 prepared_descs;
	u32 tx_xfr;
	u32 tx_dma;
	u32 tx_cmplt;
	u32 rx_procs;
	u32 rx_data;
} __packed;

struct wl18xx_acx_tx_stats {
	u32 tx_template_prepared;
	u32 tx_data_prepared;
	u32 tx_template_programmed;
	u32 tx_data_programmed;
	u32 tx_burst_programmed;
	u32 tx_starts;
	u32 tx_imm_resp;
	u32 tx_start_templates;
	u32 tx_start_int_templates;
	u32 tx_start_fw_gen;
	u32 tx_start_data;
	u32 tx_start_null_frame;
	u32 tx_exch;
	u32 tx_retry_template;
	u32 tx_retry_data;
	u32 tx_exch_pending;
	u32 tx_exch_expiry;
	u32 tx_exch_mismatch;
	u32 tx_done_template;
	u32 tx_done_data;
	u32 tx_done_int_template;
	u32 tx_pre_xfr;
	u32 tx_xfr;
	u32 tx_xfr_out_of_mem;
	u32 tx_dma_programmed;
	u32 tx_dma_done;
} __packed;

struct wl18xx_acx_rx_stats {
	u32 rx_out_of_mem;
	u32 rx_hdr_overflow;
	u32 rx_hw_stuck;
	u32 rx_dropped_frame;
	u32 rx_complete_dropped_frame;
	u32 rx_alloc_frame;
	u32 rx_done_queue;
	u32 rx_done;
	u32 rx_defrag;
	u32 rx_defrag_end;
	u32 rx_mic;
	u32 rx_mic_end;
	u32 rx_xfr;
	u32 rx_xfr_end;
	u32 rx_cmplt;
	u32 rx_pre_complt;
	u32 rx_cmplt_task;
	u32 rx_phy_hdr;
	u32 rx_timeout;
} __packed;

struct wl18xx_acx_dma_stats {
	u32 rx_dma_errors;
	u32 tx_dma_errors;
} __packed;

struct wl18xx_acx_isr_stats {
	u32 irqs;
} __packed;

struct wl18xx_acx_wep_stats {
	u32 wep_add_key_count;
	u32 wep_default_key_count;
	u32 wep_key_not_found;
	u32 wep_decrypt_fail;
	u32 wep_encrypt_fail;
	u32 wep_dec_packets;
	u32 wep_dec_interrupt;
	u32 wep_enc_packets;
	u32 wep_enc_interrupts;
} __packed;

#define PWR_STAT_MAX_CONT_MISSED_BCNS_SPREAD 10

struct wl18xx_acx_pwr_stats {
	u32 missing_bcns_cnt;
	u32 rcvd_bcns_cnt;
	u32 connection_out_of_sync;
	u32 cont_miss_bcns_spread[PWR_STAT_MAX_CONT_MISSED_BCNS_SPREAD];
	u32 rcvd_awake_bcns_cnt;
} __packed;

struct wl18xx_acx_mic_stats {
	u32 mic_rx_pkts;
	u32 mic_calc_failure;
} __packed;

struct wl18xx_acx_aes_stats {
	u32 aes_encrypt_fail;
	u32 aes_decrypt_fail;
	u32 aes_encrypt_packets;
	u32 aes_decrypt_packets;
	u32 aes_encrypt_interrupt;
	u32 aes_decrypt_interrupt;
} __packed;

struct wl18xx_acx_gem_stats {
	u32 gem_encrypt_fail;
	u32 gem_decrypt_fail;
	u32 gem_encrypt_packets;
	u32 gem_decrypt_packets;
	u32 gem_encrypt_interrupt;
	u32 gem_decrypt_interrupt;
} __packed;

struct wl18xx_acx_event_stats {
	u32 calibration;
	u32 rx_mismatch;
	u32 rx_mem_empty;
} __packed;

struct wl18xx_acx_ps_poll_stats {
	u32 ps_poll_timeouts;
	u32 upsd_timeouts;
	u32 upsd_max_ap_turn;
	u32 ps_poll_max_ap_turn;
	u32 ps_poll_utilization;
	u32 upsd_utilization;
} __packed;

struct wl18xx_acx_rx_filter_stats {
	u32 beacon_filter;
	u32 arp_filter;
	u32 mc_filter;
	u32 dup_filter;
	u32 data_filter;
	u32 ibss_filter;
	u32 protection_filter;
} __packed;

struct wl18xx_acx_calibration_stats {
	u32 init_cal_total;
	u32 init_radio_bands_fail;
	u32 init_set_params;
	u32 init_tx_clpc_fail;
	u32 init_rx_iw_mm_fail;
	u32 tune_cal_total;
	u32 tune_drpw_rtrim_fail;
	u32 tune_drpw_pd_buf_fail;
	u32 tune_drpw_tx_mix_freq_fail;
	u32 tune_drpw_ta_cal;
	u32 tune_drpw_rx_if_2_gain;
	u32 tune_drpw_rx_dac;
	u32 tune_drpw_chan_tune;
	u32 tune_drpw_rx_tx_lpf;
	u32 tune_drpw_lna_tank;
	u32 tune_tx_lo_leak_fail;
	u32 tune_tx_iq_mm_fail;
	u32 tune_tx_pdet_fail;
	u32 tune_tx_ppa_fail;
	u32 tune_tx_clpc_fail;
	u32 tune_rx_ana_dc_fail;
	u32 tune_rx_dig_dc_fail; /* check if this is needed */
	u32 tune_rx_iq_mm_fail;
	u32 cal_state_fail;
} __packed;

struct wl18xx_acx_statistics {
	struct acx_header header;

	struct wl18xx_acx_ring_stats		ring;
	struct wl18xx_acx_debug_stats		debug;
	struct wl18xx_acx_tx_stats		tx;
	struct wl18xx_acx_rx_stats		rx;
	struct wl18xx_acx_dma_stats		dma;
	struct wl18xx_acx_isr_stats		isr;
	struct wl18xx_acx_wep_stats		wep;
	struct wl18xx_acx_pwr_stats		pwr;
	struct wl18xx_acx_aes_stats		aes;
	struct wl18xx_acx_mic_stats		mic;
	struct wl18xx_acx_event_stats		event;
	struct wl18xx_acx_ps_poll_stats		ps_poll;
	struct wl18xx_acx_rx_filter_stats	rx_filter;
	struct wl18xx_acx_calibration_stats	calibration;
	struct wl18xx_acx_gem_stats		gem;
} __packed;

int wl18xx_acx_host_if_cfg_bitmap(struct wl1271 *wl, u32 host_cfg_bitmap,
				  u32 sdio_blk_size, u32 extra_mem_blks,
				  u32 len_field_size);
int wl18xx_acx_set_checksum_state(struct wl1271 *wl);

#endif /* __WL18XX_ACX_H__ */
