<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Login extends CI_Controller {
    public function check_login()
    {
        $this->load->model('Account_model');
        $username=$this->input->get('owner_ID');
        $plaintext_password=$this->input->get('salt_and_hash');
        $encrypted_password=$this->Account_model->login($username);

        if(password_verify($plaintext_password,$encrypted_password)){
          $result=true;
        }
        else{
          $result=false;
        }
        echo json_encode($result);
    }
}
