<?php
/**
 *
 */
class Card_model extends CI_model
{
  $this->db->select('*');
    $this->db->from('card');
    if($id !== NULL) {
      $this->db->where('card_number',$id);
    }
    return $this->db->get()->result_array();
  }

}