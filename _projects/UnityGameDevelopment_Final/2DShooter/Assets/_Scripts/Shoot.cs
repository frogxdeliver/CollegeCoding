using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shoot : MonoBehaviour
{
    public GameObject bulletPrefab;
    public Transform launchPosition;
    public float turnSpeed = 60f;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {


        //mouse firing
        if (Input.GetMouseButtonDown(0))
        {
            if (!IsInvoking("fireBullet"))
            {
                InvokeRepeating("fireBullet", 0f, 0.1f);
                
            }
        }
        if (Input.GetMouseButtonUp(0))
        {
            CancelInvoke("fireBullet");
        }
    }

    void fireBullet()
    {
        Rigidbody bullet = createBullet();

        
    }

    private Rigidbody createBullet()
    {
        GetComponent<AudioSource>().Play();
        GameObject bullet = Instantiate(bulletPrefab) as GameObject;
        bullet.transform.position = launchPosition.position;
        return bullet.GetComponent<Rigidbody>();
    }

}
