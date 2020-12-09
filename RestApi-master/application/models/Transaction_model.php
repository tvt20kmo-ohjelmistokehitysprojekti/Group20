<?php
/**
 *
 */
class Transaction_model extends CI_model
{
  function get_transaction($id)
  {
    $this->db->select('*');
    $this->db->from('transaction');
    if($id !== NULL) {
      $this->db->where('idtransaction',$id);
    }
    return $this->db->get()->result_array();
  }

  function withdraw($id, $update_data)
  {
  	$this->db->where('idtransaction', $id);
  	$this->db->update('transaction', $update_data);
  	if($this->db->affected_rows()>0)
  	{
  		return TRUE;
  	}
  	else
  	{
  		return FALSE;
  	}
  }

}