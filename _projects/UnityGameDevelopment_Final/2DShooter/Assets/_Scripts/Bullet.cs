using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    public Rigidbody2D rb;
    private Vector2 target;

    // Start is called before the first frame update
    void Start()
    {
        //https://www.youtube.com/watch?v=mKLp-2iseDc&t=6s
        Vector2 direction = Camera.main.ScreenToWorldPoint(Input.mousePosition) - transform.position;
        rb.velocity = direction * 2; //2 is the speed
    }

    // Update is called once per frame
    void Update()
    {
        //https://www.youtube.com/watch?v=RZTpDxgrDkQ
        /*if (Vector2.Distance(transform.position, target) < 0.2f)
        {
            Destroy(gameObject);
        }*/
    }

    void OnBecameInvisible()
    {
        Destroy(gameObject);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        Destroy(gameObject);

    }
}
