using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeathExplosion : MonoBehaviour
{
    private ParticleSystem deathExplosion;
    private bool didStart = false;

    public void Activate()
    {
        didStart = true;
        deathExplosion.Play();

        if (didStart && deathExplosion.isStopped)
        {
            Destroy(gameObject);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        deathExplosion = GetComponent<ParticleSystem>();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
