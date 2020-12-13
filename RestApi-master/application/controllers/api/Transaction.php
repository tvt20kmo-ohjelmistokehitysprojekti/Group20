<?php

defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use __autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */
require APPPATH . 'libraries/REST_Controller.php';

/**
 * This is an example of a RestApi based on PHP and CodeIgniter 3.
 * 
 *
 * @package         CodeIgniter
 * @subpackage      Rest Server
 * @category        Controller
 * @author          Pekka Alaluukas (edited the version made by Phil Sturgeon & Chris Kacerguis)
 * @license         MIT
 * @link            https://github.com/chriskacerguis/codeigniter-restserver
 */
class Transaction extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Transaction_model');
    }

    // Get transaction from database
    public function Transaction_get()
    {
    	
    	$id = $this->get('id');

    	// If id doesn't exist return all transactions
    	if($id === NULL)
    	{
    		$transaction = $this->Transaction_model->get_transaction(NULL);

    		if($id)
    		{
    		//Set response and exit
    			$this->response($id, REST_Controller::HTTP_OK);
    		}
    		else
    		{
    			$this->response([
    				'status' => FALSE,
    				'message' => 'Transaction was not found'
    			], REST_Controller::HTTP_NOT_FOUND);
    		}
    	}
    	// Find and return particular transaction
    	else
    	{

    		//Validate id
    		if($id <= 0)
    		{
    			//Invalid id
    			$this->response(NULL, REST_Controller::HTTP_BAD_REQUEST);
    		}

        $transaction = $this->Transaction_model->get_transaction($id);

    	  if(!empty($transaction))
    		{
    			$this->set_response($transaction, REST_Controller::HTTP_OK);
    		}
    		else
    		{
    			$this->set_response([
    				'status' => FALSE,
    				'message' => 'Transaction could not be found'
    			], REST_Controller::HTTP_NOT_FOUND);
    		}
    	}
    }
   	public function add_transaction()
   	{
   		$add_transaction = array(
   			'time' => $this->post('time'),
   			'balance_change' => $this->post('balance_change')
   		);
   		$insert_id = $this->Transaction_model->withdraw($add_transaction);
   		if($insert_id)
   		{
   			$message = [
   				'transaction' => $insert_id,
   				'time' => $this->post('time'),
   				'message' => 'Transaction added',
   			];
   			$this->set_response($message, REST_Controller::HTTP_CREATED);
   		}
   		else
   		{
   		$this->set_response([
    			'status' => FALSE,
   				'message' => 'Transaction could not be found'
   			], REST_Controller::HTTP_CONFLICT);
   		}
   	}
}