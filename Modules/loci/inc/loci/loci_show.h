/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

#if !defined(_LOCI_SHOW_H_)
#define _LOCI_SHOW_H_

#include <loci/loci_base.h>
#include <loci/of_match.h>
#include <stdio.h>

/* g++ requires this to pick up PRI, etc.
 * See  http://gcc.gnu.org/ml/gcc-help/2006-10/msg00223.html
 */
#if !defined(__STDC_FORMAT_MACROS)
#define __STDC_FORMAT_MACROS
#endif
#include <inttypes.h>

typedef int (*loci_obj_show_f)(loci_writer_f writer,
                               void *cookie, of_object_t *obj);

/****************************************************************
 *
 * Per-datatype dump macros
 *
 ****************************************************************/
#define LOCI_SHOW_u8(writer, cookie, val) writer(cookie, "%u", (val))
#define LOCI_SHOW_u16(writer, cookie, val) writer(cookie, "%u (0x%x)", (val), (val))
#define LOCI_SHOW_u32(writer, cookie, val) writer(cookie, "%u (0x%x)", (val), (val))
#define LOCI_SHOW_u64(writer, cookie, val) writer(cookie, "%" PRIu64 "(0x%" PRIx64 ")", (val), (val))

#define LOCI_SHOW_D_INT(cookie, macro, val) writer(cookie, "%" macro , val); 
#define LOCI_SHOW_X_INT(cookie, macro, val) writer(cookie, "0x%" macro, val); 

#define LOCI_SHOW_x8(writer, cookie, val) LOCI_SHOW_X_INT(cookie,  PRIx8, val)
#define LOCI_SHOW_x16(writer, cookie, val) LOCI_SHOW_X_INT(cookie, PRIx16, val)
#define LOCI_SHOW_x32(writer, cookie, val) LOCI_SHOW_X_INT(cookie, PRIx32, val)
#define LOCI_SHOW_x64(writer, cookie, val) LOCI_SHOW_X_INT(cookie, PRIx64, val)
#define LOCI_SHOW_d8(writer, cookie, val) LOCI_SHOW_D_INT(cookie, PRId8, val)
#define LOCI_SHOW_d16(writer, cookie, val) LOCI_SHOW_D_INT(cookie, PRId16, val)
#define LOCI_SHOW_d32(writer, cookie, val) LOCI_SHOW_D_INT(cookie, PRId32, val)
#define LOCI_SHOW_d64(writer, cookie, val) LOCI_SHOW_D_INT(cookie, PRId64, val)



/**
 * Field-specific show macros. 
 */
#define LOCI_SHOW_u32_ipv6_flabel(writer, cookie, val)     LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u8_vlan_pcp(writer, cookie, val)         LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u32_ipv4_src(writer, cookie, val)        LOCI_SHOW_ipv4(writer, cookie, val)
#define LOCI_SHOW_ipv6_ipv6_dst(writer, cookie, val)       LOCI_SHOW_ipv6(writer, cookie, val)
#define LOCI_SHOW_u32_arp_tpa(writer, cookie, val)         LOCI_SHOW_ipv4(writer, cookie, val)
#define LOCI_SHOW_u8_icmpv6_type(writer, cookie, val)      LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_mac_arp_sha(writer, cookie, val)         LOCI_SHOW_mac(writer, cookie, val)
#define LOCI_SHOW_ipv6_ipv6_src(writer, cookie, val)       LOCI_SHOW_ipv6(writer, cookie, val)
#define LOCI_SHOW_u16_sctp_src(writer, cookie, val)        LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u8_icmpv6_code(writer, cookie, val)      LOCI_SHOW_x8(writer, cookie, val)
#define LOCI_SHOW_mac_eth_dst(writer, cookie, val)         LOCI_SHOW_mac(writer, cookie, val)
#define LOCI_SHOW_mac_ipv6_nd_sll(writer, cookie, val)     LOCI_SHOW_mac(writer, cookie, val)
#define LOCI_SHOW_u8_mpls_tc(writer, cookie, val)          LOCI_SHOW_x8(writer, cookie, val)
#define LOCI_SHOW_u16_arp_op(writer, cookie, val)          LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u16_eth_type(writer, cookie, val)        LOCI_SHOW_x16(writer, cookie, val)
#define LOCI_SHOW_ipv6_ipv6_nd_target(writer, cookie, val) LOCI_SHOW_ipv6(writer, cookie, val)
#define LOCI_SHOW_u16_vlan_vid(writer, cookie, val)        LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_mac_arp_tha(writer, cookie, val)         LOCI_SHOW_mac(writer, cookie, val)
#define LOCI_SHOW_port_no_in_port(writer, cookie, val)     LOCI_SHOW_port_no(writer, cookie, val)
#define LOCI_SHOW_u8_ip_dscp(writer, cookie, val)          LOCI_SHOW_x8(writer, cookie, val)
#define LOCI_SHOW_u16_sctp_dst(writer, cookie, val)        LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u8_icmpv4_code(writer, cookie, val)      LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u16_tcp_src(writer, cookie, val)         LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u32_arp_spa(writer, cookie, val)         LOCI_SHOW_ipv4(writer, cookie, val)
#define LOCI_SHOW_u8_ip_ecn(writer, cookie, val)           LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u16_udp_dst(writer, cookie, val)         LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_port_no_in_phy_port(writer, cookie, val) LOCI_SHOW_port_no(writer, cookie, val)
#define LOCI_SHOW_u32_ipv4_dst(writer, cookie, val)        LOCI_SHOW_ipv4(writer, cookie, val)
#define LOCI_SHOW_mac_eth_src(writer, cookie, val)         LOCI_SHOW_mac(writer, cookie, val)
#define LOCI_SHOW_u16_udp_src(writer, cookie, val)         LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_mac_ipv6_nd_tll(writer, cookie, val)     LOCI_SHOW_mac(writer, cookie, val)
#define LOCI_SHOW_u8_icmpv4_type(writer, cookie, val)      LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u32_mpls_label(writer, cookie, val)      LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u16_tcp_dst(writer, cookie, val)         LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u8_ip_proto(writer, cookie, val)         LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u64_metadata(writer, cookie, val)        LOCI_SHOW_x64(writer, cookie, val)
#define LOCI_SHOW_u8_enabled(writer, cookie, val)          LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u32_vport_no(writer, cookie, val)        LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_port_no(writer, cookie, val)         LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u16_ingress_tpid(writer, cookie, val)    LOCI_SHOW_x16(writer, cookie, val)
#define LOCI_SHOW_u16_egress_tpid(writer, cookie, val)     LOCI_SHOW_x16(writer, cookie, val)
#define LOCI_SHOW_u16_ingress_vlan_id(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u16_egress_vlan_id(writer, cookie, val)  LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u32_enabled(writer, cookie, val)         LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_enable(writer, cookie, val)          LOCI_SHOW_u32(writer, cookie, val)




/* @todo Add checks for special port numbers */
#define LOCI_SHOW_port_no(writer, cookie, val) writer(cookie, "%d", val)
#define LOCI_SHOW_fm_cmd(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)

/* @todo Decode wildcards */
#define LOCI_SHOW_wc_bmap(writer, cookie, val)         \
    writer(cookie, "0x%" PRIx64, (val))
#define LOCI_SHOW_match_bmap(writer, cookie, val)      \
    writer(cookie, "0x%" PRIx64, (val))

/* @todo Dump first N bytes of data */
#define LOCI_SHOW_octets(writer, cookie, val)                                      \
    writer(cookie, "%d bytes at location %p", (val).bytes, (val).data)

#define LOCI_SHOW_mac(writer, cookie, val)                                 \
    writer(cookie, "%02x:%02x:%02x:%02x:%02x:%02x",            \
               (val).addr[0], (val).addr[1], (val).addr[2],     \
               (val).addr[3], (val).addr[4], (val).addr[5])

#define LOCI_SHOW_ipv4(writer, cookie, val)                                        \
    writer(cookie, "%d.%d.%d.%d", val >> 24, (val >> 16) & 0xff,       \
               (val >> 8) & 0xff, val & 0xff)

#define LOCI_SHOW_ipv6(writer, cookie, val)                                        \
    writer(cookie, "%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x", \
               (val).addr[0], (val).addr[1], (val).addr[2], (val).addr[3], \
               (val).addr[4], (val).addr[5], (val).addr[6], (val).addr[7], \
               (val).addr[8], (val).addr[9], (val).addr[10], (val).addr[11], \
               (val).addr[12], (val).addr[13], (val).addr[14], (val).addr[15])

#define LOCI_SHOW_string(writer, cookie, val) writer(cookie, "%s", val)

#define LOCI_SHOW_port_name(writer, cookie, val) LOCI_SHOW_string(writer, cookie, val)
#define LOCI_SHOW_tab_name(writer, cookie, val) LOCI_SHOW_string(writer, cookie, val)
#define LOCI_SHOW_desc_str(writer, cookie, val) LOCI_SHOW_string(writer, cookie, val)
#define LOCI_SHOW_ser_num(writer, cookie, val) LOCI_SHOW_string(writer, cookie, val)

int loci_show_match(loci_writer_f writer, void *cookie, of_match_t *match);
#define LOCI_SHOW_match(writer, cookie, val) loci_show_match(writer, cookie, &val)

/**
 * Generic version for any object
 */
int of_object_show(loci_writer_f writer, void *cookie, of_object_t *obj);




/**
 * Choose a representation for each field that 
 * makes the most sense for display to the user. 
 */
#define LOCI_SHOW_u32_xid(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u16_flags(writer, cookie, val) LOCI_SHOW_x16(writer, cookie, val)
#define LOCI_SHOW_u64_packet_count(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_byte_count(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u32_flow_count(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_match_match(writer, cookie, val) LOCI_SHOW_match(writer, cookie, val)
#define LOCI_SHOW_u8_table_id(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_port_no_out_port(writer, cookie, val) LOCI_SHOW_port_no(writer, cookie, val)
#define LOCI_SHOW_u32_experimenter(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_subtype(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u8_index(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u32_mask(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val) LOCI_SHOW_x8(writer, cookie, val)
#define LOCI_SHOW_desc_str_mfr_desc(writer, cookie, val) LOCI_SHOW_desc_str(writer, cookie, val)
#define LOCI_SHOW_desc_str_hw_desc(writer, cookie, val) LOCI_SHOW_desc_str(writer, cookie, val)
#define LOCI_SHOW_desc_str_sw_desc(writer, cookie, val) LOCI_SHOW_desc_str(writer, cookie, val)
#define LOCI_SHOW_ser_num_serial_num(writer, cookie, val) LOCI_SHOW_ser_num(writer, cookie, val)
#define LOCI_SHOW_desc_str_dp_desc(writer, cookie, val) LOCI_SHOW_desc_str(writer, cookie, val)
#define LOCI_SHOW_octets_data(writer, cookie, val) LOCI_SHOW_octets(writer, cookie, val)
#define LOCI_SHOW_u16_err_type(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u16_code(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u64_datapath_id(writer, cookie, val) LOCI_SHOW_x64(writer, cookie, val)
#define LOCI_SHOW_u32_n_buffers(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u8_n_tables(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u32_capabilities(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_actions(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u64_cookie(writer, cookie, val) LOCI_SHOW_x64(writer, cookie, val)
#define LOCI_SHOW_u16_idle_timeout(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u16_hard_timeout(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u16_priority(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u32_buffer_id(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u8_reason(writer, cookie, val) LOCI_SHOW_x8(writer, cookie, val)
#define LOCI_SHOW_u32_duration_sec(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_duration_nsec(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u16_miss_send_len(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u32_role(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u16_total_len(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_port_no_port_no(writer, cookie, val) LOCI_SHOW_port_no(writer, cookie, val)
#define LOCI_SHOW_mac_hw_addr(writer, cookie, val) LOCI_SHOW_mac(writer, cookie, val)
#define LOCI_SHOW_u32_config(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_advertise(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_port_no_port(writer, cookie, val) LOCI_SHOW_port_no(writer, cookie, val)
#define LOCI_SHOW_u32_queue_id(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_dest_port(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_vlan_tag(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u8_copy_stage(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u16_max_len(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_mac_dl_addr(writer, cookie, val) LOCI_SHOW_mac(writer, cookie, val)
#define LOCI_SHOW_u32_nw_addr(writer, cookie, val) LOCI_SHOW_ipv4(writer, cookie, val)
#define LOCI_SHOW_u8_nw_tos(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u16_tp_port(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_wc_bmap_wildcards(writer, cookie, val) LOCI_SHOW_wc_bmap(writer, cookie, val)
#define LOCI_SHOW_port_name_name(writer, cookie, val) LOCI_SHOW_port_name(writer, cookie, val)
#define LOCI_SHOW_u32_state(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_curr(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_advertised(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_supported(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_peer(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u64_rx_packets(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_tx_packets(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_rx_bytes(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_tx_bytes(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_rx_dropped(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_tx_dropped(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_rx_errors(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_tx_errors(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_rx_frame_err(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_rx_over_err(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_rx_crc_err(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_collisions(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u16_rate(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_tab_name_name(writer, cookie, val) LOCI_SHOW_tab_name(writer, cookie, val)
#define LOCI_SHOW_u32_max_entries(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_active_count(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u64_lookup_count(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_matched_count(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u32_out_group(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u64_cookie_mask(writer, cookie, val) LOCI_SHOW_x64(writer, cookie, val)
#define LOCI_SHOW_u32_reserved(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u16_command(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u8_group_type(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u32_group_id(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u16_ethertype(writer, cookie, val) LOCI_SHOW_x16(writer, cookie, val)
#define LOCI_SHOW_u8_mpls_ttl(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u8_nw_ecn(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u8_nw_ttl(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u16_weight(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_port_no_watch_port(writer, cookie, val) LOCI_SHOW_port_no(writer, cookie, val)
#define LOCI_SHOW_u32_watch_group(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_ref_count(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u64_metadata_mask(writer, cookie, val) LOCI_SHOW_x64(writer, cookie, val)
#define LOCI_SHOW_mac_eth_src_mask(writer, cookie, val) LOCI_SHOW_mac(writer, cookie, val)
#define LOCI_SHOW_mac_eth_dst_mask(writer, cookie, val) LOCI_SHOW_mac(writer, cookie, val)
#define LOCI_SHOW_u32_ipv4_src_mask(writer, cookie, val) LOCI_SHOW_ipv4(writer, cookie, val)
#define LOCI_SHOW_u32_ipv4_dst_mask(writer, cookie, val) LOCI_SHOW_ipv4(writer, cookie, val)
#define LOCI_SHOW_u32_curr_speed(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_max_speed(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_match_bmap_match(writer, cookie, val) LOCI_SHOW_match_bmap(writer, cookie, val)
#define LOCI_SHOW_u32_instructions(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_write_actions(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_apply_actions(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_types(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_max_groups_all(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_max_groups_select(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_max_groups_indirect(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_max_groups_ff(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_actions_all(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_actions_select(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_actions_indirect(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_actions_ff(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u64_generation_id(writer, cookie, val) LOCI_SHOW_x64(writer, cookie, val)
#define LOCI_SHOW_octets_field(writer, cookie, val) LOCI_SHOW_octets(writer, cookie, val)
#define LOCI_SHOW_u16_value(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u16_value_mask(writer, cookie, val) LOCI_SHOW_x16(writer, cookie, val)
#define LOCI_SHOW_mac_value(writer, cookie, val) LOCI_SHOW_mac(writer, cookie, val)
#define LOCI_SHOW_mac_value_mask(writer, cookie, val) LOCI_SHOW_mac(writer, cookie, val)
#define LOCI_SHOW_u32_value(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_value_mask(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_oxm_header(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u8_value(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u8_value_mask(writer, cookie, val) LOCI_SHOW_x8(writer, cookie, val)
#define LOCI_SHOW_port_no_value(writer, cookie, val) LOCI_SHOW_port_no(writer, cookie, val)
#define LOCI_SHOW_port_no_value_mask(writer, cookie, val) LOCI_SHOW_port_no(writer, cookie, val)
#define LOCI_SHOW_ipv6_value(writer, cookie, val) LOCI_SHOW_ipv6(writer, cookie, val)
#define LOCI_SHOW_ipv6_value_mask(writer, cookie, val) LOCI_SHOW_ipv6(writer, cookie, val)
#define LOCI_SHOW_u64_value(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_value_mask(writer, cookie, val) LOCI_SHOW_x64(writer, cookie, val)
#define LOCI_SHOW_u64_write_setfields(writer, cookie, val) LOCI_SHOW_x64(writer, cookie, val)
#define LOCI_SHOW_u64_apply_setfields(writer, cookie, val) LOCI_SHOW_x64(writer, cookie, val)
#define LOCI_SHOW_u64_metadata_match(writer, cookie, val) LOCI_SHOW_x64(writer, cookie, val)
#define LOCI_SHOW_u64_metadata_write(writer, cookie, val) LOCI_SHOW_x64(writer, cookie, val)
#define LOCI_SHOW_u32_packet_in_mask_equal_master(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_packet_in_mask_slave(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_port_status_mask_equal_master(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_port_status_mask_slave(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_flow_removed_mask_equal_master(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u32_flow_removed_mask_slave(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u8_auxiliary_id(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u32_meter_id(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_rate(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_burst_size(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u8_prec_level(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u64_packet_band_count(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_byte_band_count(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u32_max_meter(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_band_types(writer, cookie, val) LOCI_SHOW_x32(writer, cookie, val)
#define LOCI_SHOW_u8_max_bands(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u8_max_color(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u64_packet_in_count(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_u64_byte_in_count(writer, cookie, val) LOCI_SHOW_u64(writer, cookie, val)
#define LOCI_SHOW_octets_experimenter_data(writer, cookie, val) LOCI_SHOW_octets(writer, cookie, val)
#define LOCI_SHOW_u32_dst(writer, cookie, val)        LOCI_SHOW_ipv4(writer, cookie, val)
#define LOCI_SHOW_u32_service(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u32_status(writer, cookie, val) LOCI_SHOW_u32(writer, cookie, val)
#define LOCI_SHOW_u16_subtype(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)
#define LOCI_SHOW_u32_ipv4_addr(writer, cookie, val) LOCI_SHOW_ipv4(writer, cookie, val)
#define LOCI_SHOW_u32_ipv4_netmask(writer, cookie, val) LOCI_SHOW_ipv4(writer, cookie, val)
#define LOCI_SHOW_u8_l2_table_enable(writer, cookie, val) LOCI_SHOW_u8(writer, cookie, val)
#define LOCI_SHOW_u16_l2_table_priority(writer, cookie, val) LOCI_SHOW_u16(writer, cookie, val)



#endif /* _LOCI_SHOW_H_ */
