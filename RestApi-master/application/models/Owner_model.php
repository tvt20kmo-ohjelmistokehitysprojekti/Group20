<?php
/**
 *
 */
class Owner_model extends CI_model
{
  function get_owner($id){
    $this->db->select('*');
    $this->db->from('owner-account');
    if($id !== NULL) {
      $this->db->where('owner_ID',$id);
    }
    return $this->db->get()->result_array();
  }

}