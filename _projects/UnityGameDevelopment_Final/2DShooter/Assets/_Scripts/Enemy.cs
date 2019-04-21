//used for enemy AI
//https://www.youtube.com/watch?v=RZTpDxgrDkQ
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

public class Enemy : MonoBehaviour
{
    
    public bool isAlive = true; //used to track enemy's state
    public UnityEvent OnDestroy;
    //public SpriteRenderer playerSprite;

    public float speed;
    private Transform playerPos;

    // Start is called before the first frame update
    void Start()
    {
        playerPos = GameObject.FindGameObjectWithTag("Player").GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update()
    {
        //if (playerPos != null) //stops movement when the player is dead
        /*if (!GameObject.FindGameObjectWithTag("Player").GetComponent<SpriteRenderer>().enabled)
        {
            
        }*/
        transform.position = Vector2.MoveTowards(transform.position, playerPos.position, speed * Time.deltaTime);
        
        
    }
    
    void OnTriggerEnter2D(Collider2D other)
    {
        /*if (other.CompareTag("Bullet"))
        {
            Destroy(other.gameObject);
            Destroy(gameObject);
        }*/
        /*if (other.CompareTag("Player"))
        {
            //player.lives--;
            Destroy(gameObject);
        }*/

        if (isAlive)
        {
            Die();
        }
    }

    public void Die()
    {
        //isAlive = false;
        SoundManager.Instance.PlayOneShot(SoundManager.Instance.enemyExplosion);
        OnDestroy.Invoke();
        OnDestroy.RemoveAllListeners();

        Destroy(gameObject);
        
    }
}
