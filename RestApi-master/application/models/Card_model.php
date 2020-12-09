<?php
/**
 *
 */
class Card_model extends CI_model
{
  function get_card($id){
    $this->db->select('*');
    $this->db->from('account-card');
    if($id !== NULL) {
      $this->db->where('account_ID',$id);
    }
    return $this->db->get()->result_array();
  }

}