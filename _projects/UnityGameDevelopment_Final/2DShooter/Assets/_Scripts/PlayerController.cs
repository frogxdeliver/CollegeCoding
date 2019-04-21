//https://unity3d.com/learn/tutorials/projects/space-shooter-tutorial/moving-player?playlist=17147
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

//boundary for the screen
//yoinked from shapeship tutorial
[System.Serializable]
public class Boundary
{
    public float xMin, xMax, yMin, yMax;
}


public class PlayerController : MonoBehaviour
{
    public GameObject destructionFX;
    public Text livesText;
    public Text gameOverText;
    public Text restartText;

    public SpriteRenderer ship;
    public SpriteRenderer flames;
    public SpriteRenderer lines;

    public int lives = 3;
    public string livesString;
    public float moveSpeed = 10f;
    public float turnSpeed = 60f;
    public Boundary boundary;

    public LayerMask layerMask;
    private Vector2 currentLookTarget = Vector2.zero;
    
    private bool isHit = false;
    private float timeSinceHit = 0;
    public float timeBetweenHits = 2.5f;

    private bool gameOver;
    public bool restart;

    //private DeathExplosion deathExplosion;
    //public DeathExplosion deathExplosion;

    /*public DeathExplosion GetDeathExplosion()
    {
        //if (deathExplosion == null)
        //{
            deathExplosion = GetComponentInChildren<DeathExplosion>();
        //}
        return deathExplosion;
    }*/

    // Start is called before the first frame update
    void Start()
    {
        //deathExplosion = gameObject.GetComponentInChildren<DeathExplosion>();

        livesString = "Lives: " + lives;
        livesText.text = livesString;
        gameOver = false;
        restart = false;
        restartText.text = "";
        gameOverText.text = "";
    }

    private void FixedUpdate()
    {
        //movement yoinked from the shapeship tuturoial
        float moveHorizontal = Input.GetAxis("Horizontal");
        float moveVertical = Input.GetAxis("Vertical");

        Vector2 movement = new Vector2(moveHorizontal, moveVertical);

        GetComponent<Rigidbody2D>().velocity = movement * moveSpeed;

        GetComponent<Rigidbody2D>().position = new Vector3
            (
                //Mathf.Clamp restricts player movements within the boundaries of the x, y, and z axis 
                //In this case, we are only using x and z, since we are moving across a 2-D plane
                Mathf.Clamp(GetComponent<Rigidbody2D>().position.x, boundary.xMin, boundary.xMax),
                Mathf.Clamp(GetComponent<Rigidbody2D>().position.y, boundary.yMin, boundary.yMax)
            );

        //https://www.youtube.com/watch?v=mKLp-2iseDc&t=6s
        //ship's direction
        Vector2 direction = Camera.main.ScreenToWorldPoint(Input.mousePosition) - transform.position;
        float angle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg;
        Quaternion rotation = Quaternion.AngleAxis(angle, Vector3.forward);
        transform.rotation = Quaternion.Slerp(transform.rotation, rotation, turnSpeed * Time.deltaTime);
    }

    void Update()
    {
        /*Vector3 moveDirection = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical"));
        characterController.SimpleMove(moveDirection * moveSpeed);*/

        if (restart)
        {
            if (Input.GetKeyDown(KeyCode.R))
            {
                SceneManager.LoadScene("Game");
            }
        }

        if (isHit)
        {
            timeSinceHit += Time.deltaTime;
            if (timeSinceHit > timeBetweenHits)
            {
                isHit = false;
                timeSinceHit = 0;
            }
        }

        
    }

    public void OnTriggerEnter2D(Collider2D other)
    {
        Enemy enemy = other.gameObject.GetComponent<Enemy>();
        if (enemy != null) // as long as an object has an enemy script attached to it (it's an enemy)
        {
            if (!isHit)
            {
                //update lives & UI
                lives -= 1;
                livesString = "Lives: " + lives;
                livesText.text = livesString;

                if (lives > 0) // as long as the player's lives don't hit 0
                {
                    Debug.Log("total lives: " + lives);
                }
                else
                {
                    //Die();
                    //Instead of killing the player, I make the sprites vanish
                    //Had to do this because of using the text on this script instead of the gameManager
                    playerVanish();
                    GameOver();
                }
                isHit = true; //indicates to leave the loop due to the player being hit
                //sounds effects here if time allows for it
            }
            enemy.Die();

        }
    }
    public void GameOver()
    {
        gameOverText.text = "Game Over :(";
        gameOver = true;
        restartText.text = "Press 'R' for Restart";
        restart = true;
    }

    public void Die()
    {
        Destroy(gameObject);

        
    }

    public void playerVanish()
    {
        //ship flames lines
        ship.enabled = false;
        flames.enabled = false;
        lines.enabled = false;

        //GetDeathExplosion();
        //deathExplosion.transform.parent = null;
        //deathExplosion.Activate();

        //Instantiate(destructionFX, transform.position, Quaternion.identity); //generating destruction visual effect and destroying the 'Player' object
        //Destroy(gameObject);
    }
}
