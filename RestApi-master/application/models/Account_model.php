<?php
/**
 *
 */
class Account_model extends CI_model
{
  function get_account($id)
  {
    $this->db->select('*');
    $this->db->from('card');
    if($id !== NULL) {
      $this->db->where('owner_ID',$id);
    }
    return $this->db->get()->result_array();
  }
  
  function get_balance($id)
  {
    $this->db->select('*');
    $this->db->from('account');
    if($id !== NULL) {
      $this->db->where('balance',$id);
    }
    return $this->db->get()->result_array();
  }

  function login($salt)
  {
    $this->db->select('salt_and_hash');
    $this->db->from('card');
    $this->db->where('salt_and_hash', $salt);
    return $this->db->get()->row('salt');
  }
}